import multiprocessing as mp
import time
import sys
import argparse
import os
import random

MAX_WORKER = 8
EPOCH = 2000
MNUM = 1000000007


class Worker(mp.Process):
    def __init__(self, model):
        super(Worker, self).__init__(target=self.start)
        self.model = model
        self.inQ = mp.Queue()
        self.outQ = mp.Queue()

    def run(self):
        while True:
            edge, seeds = self.inQ.get()
            if self.model == 'IC':
                self.outQ.put(IC(edge, seeds))
            elif self.model == 'LT':
                self.outQ.put(LT(edge, seeds))


def IC(edge, seeds):
    random.seed(int(os.getpid() + time.time() * 10000))
    cnt = len(seeds)

    act = [0 for i in range(len(edge) + 1)]
    for i in seeds:
        act[i] = 1

    queue = list(seeds)
    head = 0
    while head < len(queue):
        now = edge[queue[head]]
        for i in range(len(now)):
            if not act[now[i][0]]:
                tmp = random.random()
                if tmp <= now[i][1]:
                    cnt += 1
                    act[now[i][0]] = 1
                    queue.append(now[i][0])
        head += 1
    return cnt


def LT(edge, seeds):
    global MNUM
    random.seed(int(os.getpid() + time.time() * 1000000 + MNUM))
    MNUM += 1

    threshold = [random.random() for i in range(len(edge) + 1)]

    acted = [0 for i in range(len(edge) + 1)]
    for i in seeds:
        acted[i] = 1

    act_set = list(seeds)

    cnt = len(seeds)
    while len(act_set) > 0:
        next_act = []
        for node in act_set:
            acted[node] = 1
            e = edge[node]
            for i in range(len(e)):
                threshold[e[i][0]] -= e[i][1]
                if threshold[e[i][0]] <= 0 and not acted[e[i][0]]:
                    next_act.append(e[i][0])
                    cnt += 1
                    acted[e[i][0]] = 1
        act_set = list(next_act)

    return cnt


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--file_name', type=str, default='network.txt')
    parser.add_argument('-s', '--seed', type=str, default='network_seeds.txt')
    parser.add_argument('-m', '--model', type=str, default='LT')
    parser.add_argument('-t', '--time_limit', type=int, default=60)
    random.seed(int(os.getpid() + time.time() * 1000000 + MNUM))
    args = parser.parse_args()
    time_limit = args.time_limit
    file_name = args.file_name
    seed = args.seed

    with open(file_name) as sys.stdin:
        n, m = map(int, input().split())
        edge = [[] for i in range(0, n + 1)]
        for i in range(m):
            data = input().split()
            u, v = map(int, data[0:2])
            w = float(data[2])
            edge[u].append([v, w])

    seeds = []
    with open(seed) as sys.stdin:
        while True:
            try:
                seeds.append(int(input()))
            except EOFError:
                break
        sys.setrecursionlimit(1000000)

    workers = []
    for i in range(MAX_WORKER):
        workers.append(Worker(args.model))
        workers[i].start()
    data = (edge, seeds)
    for i in range(EPOCH):
        workers[i % MAX_WORKER].inQ.put(data)

    tot = 0
    for i in range(EPOCH):
        tot += workers[i % MAX_WORKER].outQ.get()
    print(tot / EPOCH)

    for i in workers:
        i.terminate()

    sys.stdout.flush()
