import struct


class RDTSegment:
    HEADER_LEN = 17
    MAX_PAYLOAD_LEN = 1460
    SEGMENT_LEN = MAX_PAYLOAD_LEN + HEADER_LEN
    SEQ_NUM_LIMIT = 4294967296

    @staticmethod
    def calc_checksum(payload):
        sum = 0
        for i in payload:
            sum += i
            while sum >> 8:
                sum = sum - (2 ** 8) + 1
        return (~sum & 0xFF)

    @staticmethod
    def decode(segment):
        SYN_bit = True if segment[0] != 0 else False
        FIN_bit = True if segment[1] != 0 else False
        ACK_bit = True if segment[2] != 0 else False
        seq_num, ACK_num, length = struct.unpack('!III', segment[3:15])
        payload = segment[17:17+length]
        return RDTSegment(payload, seq_num, ACK_num, SYN_bit, FIN_bit, ACK_bit)

    def __init__(self, payload, seq_num, ACK_num, SYN_bit=False,
                 FIN_bit=False, ACK_bit=False):
        self.SYN_bit = SYN_bit
        self.FIN_bit = FIN_bit
        self.ACK_bit = ACK_bit
        self.seq_num = seq_num % self.SEQ_NUM_LIMIT
        self.ACK_num = ACK_num % self.SEQ_NUM_LIMIT
        if payload is not None and len(payload) > self.MAX_PAYLOAD_LEN:
            raise ValueError
        self.payload = payload

    def get_value(self):
        f_syn = 1 if self.SYN_bit else 0
        f_fin = 1 if self.FIN_bit else 0
        f_ack = 1 if self.ACK_bit else 0
        return f_syn, f_fin, f_ack

    def encode(self):
        f_syn, f_fin, f_ack = self.get_value()
        if self.payload:
            payload_len = len(self.payload)
        else:
            payload_len = 0
        flag = struct.pack('!BBBIIIH', f_syn, f_fin, f_ack, self.seq_num,
                           self.ACK_num, payload_len, 0)
        arr = bytearray(flag)
        if self.payload:
            arr.extend(self.payload)
        checksum = RDTSegment.calc_checksum(arr)
        arr[15] = checksum >> 8
        arr[16] = checksum & 0xFF
        arr.extend(b'\x00' * (RDTSegment.SEGMENT_LEN - len(arr)))
        return bytes(arr)
