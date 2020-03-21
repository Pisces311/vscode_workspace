import socket
from udp import UDPsocket
from rdt_segment import RDTSegment
from collections import deque


class MySocket(UDPsocket):
    WINDOW_SIZE = 6

    def __init__(self):
        super().__init__()

    def connect(self):
        while True:
            data, addr = super().recvfrom(RDTSegment.SEGMENT_LEN)
            recv_data = RDTSegment.decode(data)
            is_crpt = True if RDTSegment.calc_checksum(
                recv_data) != 0 else False
            if recv_data.ACK_bit and recv_data.syn and not is_crpt:
                rsp = RDTSegment(
                    None, recv_data.ACK_num, recv_data.seq_num+1, ACK_bit=True)
                super().sendto(rsp.encode(), addr)
                print('Connection step 3.')
                break

    def work(self, rec_seg, remote_addr, is_crpt):
        if rec_seg.syn and not is_crpt:
            rsp = RDTSegment(None, rec_seg.ACK_num,
                             rec_seg.seq_num+1, True, False, True)
            super().sendto(rsp.encode(), remote_addr)

    def accept(self):
        rec_seg, remote_addr = super().recvfrom(RDTSegment.SEGMENT_LEN)
        rec_seg = RDTSegment.decode(rec_seg)
        is_crpt = True if RDTSegment.calc_checksum(rec_seg) != 0 else False
        self.work(rec_seg, remote_addr, is_crpt)

    def close(self):
        print('Socket closed.')

    def recv(self):
        receiveTotal = bytearray()
        ptr, timeoutcnt = 0, -1
        ackSegment = RDTSegment(
            None, seq_num=0, ACK_num=RDTSegment.SEQ_NUM_LIMIT-1, ACK_bit=True)
        while True:
            try:
                raw_data, remote_addr = super().recvfrom(
                    RDTSegment.SEGMENT_LEN)
                if raw_data is not None:
                    timeoutcnt = 0
                    recvSeg = RDTSegment.decode(raw_data)
                    if recvSeg.seq_num == ptr:
                        ackSegment.ACK_num = recvSeg.seq_num+1
                        if not recvSeg.FIN_bit:
                            receiveTotal.extend(recvSeg.payload)
                        ptr = (ptr + 1) % RDTSegment.SEQ_NUM_LIMIT
                    super().sendto(ackSegment.encode(), remote_addr)
                    if recvSeg.FIN_bit:
                        print('Receiver finish!')
                        break
            except ValueError:
                super().sendto(ackSegment.encode(), remote_addr)
            except socket.timeout:
                if timeoutcnt >= 0:
                    print('Timeout, count:{}'.format(timeoutcnt))
                    timeoutcnt += 1
                    if timeoutcnt > 3:
                        super().sendto(ackSegment.encode(), remote_addr)
        print('Received all!')
        return bytes(receiveTotal), remote_addr

    def count_error(self, errors):
        if errors > 5:
            print('Connection finished with error!')
            return False
        else:
            return True

    def print_send_info(self, win, addr):
        for i in win:
            super().sendto(i.encode(), addr)
            print("Send packet, seq:{}, ACK_bit:{}".format(
                i.seq_num, i.ACK_num))

    def find_errors(self, nxt, addr):
        finSegment = RDTSegment(None, seq_num=nxt % RDTSegment.SEQ_NUM_LIMIT,
                                ACK_num=0, FIN_bit=True).encode()
        errors = 0
        while True:
            try:
                super().sendto(finSegment, addr)
                recvFinACK, remote_addr_fin = super().recvfrom(
                    RDTSegment.SEGMENT_LEN)
                if recvFinACK is None:
                    continue
                recvFinACK = RDTSegment.decode(recvFinACK)
                super().settimeout(self.time)
                if (recvFinACK.ACK_bit and recvFinACK.ACK_num
                        == nxt % RDTSegment.SEQ_NUM_LIMIT + 1):
                    print('Finished!')
                    break
            except ValueError:
                print('Error in FIN!')
                errors += 1
                if not self.count_error(errors):
                    break
            except socket.timeout:
                print('Timeout in FIN')
                errors += 1
                if not self.count_error(errors):
                    break

    def sendto(self, data, addr):
        length = len(data)
        seg_len = RDTSegment.MAX_PAYLOAD_LEN
        base, nxt, timeoutCNT = 0, 0, 0
        win = deque(maxlen=MySocket.WINDOW_SIZE)
        while base * seg_len < length:
            while base + MySocket.WINDOW_SIZE > nxt:
                packet = RDTSegment(data[nxt*seg_len:nxt*seg_len+seg_len],
                                    seq_num=nxt, ACK_num=0)
                win.append(packet)
                nxt += 1
            self.print_send_info(win, addr)
            self.settimeout(self.time)
            while True:
                try:
                    recData, remote_addr = super().recvfrom(
                        RDTSegment.SEGMENT_LEN)
                    if recData is None:
                        continue
                    assert remote_addr == addr
                    recvDecode = RDTSegment.decode(recData)
                    assert recvDecode.ACK_bit
                    self.settimeout(self.time)
                    if (recvDecode.ACK_num-1 < win[0].seq_num or
                            recvDecode.ACK_num-1 > win[-1].seq_num):
                        print('ACK_num out of order!')
                    else:
                        while len(win):
                            front = win.popleft().seq_num
                            base += 1
                            if front + 1 == recvDecode.ACK_num:
                                break
                    if len(win) == 0:
                        print('Window is empty!')
                        break
                except ValueError:
                    print('Corruption!')
                except AssertionError:
                    print('Unexpected ACK_num!')
                except socket.timeout:
                    print('Timeout: '+str(timeoutCNT))
                    timeoutCNT += 1
                    if timeoutCNT > 3:
                        timeoutCNT = 0
                        break
        self.find_errors(nxt, addr)
        print('All packets have been sent!')
