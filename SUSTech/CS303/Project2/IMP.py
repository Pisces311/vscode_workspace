import math
import time
import heapq
import random
import argparse
import numpy as np
import multiprocessing as mp
from collections import defaultdict


def comb(x, y): return math.factorial(x) / \
    (math.factorial(y) * math.factorial(x - y))


class Network:
    def __init__(self, n, m, adj_mat, adj_list, adj_list_rev):
        self.n = n
        self.m = m
        self.adj_mat = adj_mat
        self.adj_list = adj_list
        self.adj_list_rev = adj_list_rev


class Worker(mp.Process):
    def __init__(self, inQ, outQ, model, network):
        super(Worker, self).__init__(target=self.start)
        self.inQ = inQ
        self.outQ = outQ
        self.model = model
        self.network = network
        np.random.seed(int(time.time()))

    def run(self):
        while True:
            task = self.inQ.get()
            theta = task
            models = {'IC': IC, 'LT': LT}
            self.outQ.put(models[self.model](self.network, theta))


def IMM(network, k, e, _l):
    n = network.n
    _l = _l * (1 + math.log(2) / math.log(n))
    R = Sampling(network, k, e, _l)
    seeds = NodeSelection(R, k)[0]
    return seeds


def Sampling(network, k, e, l):
    global worker, worker_num, model
    R = list()
    LB = 1
    _e = math.sqrt(2) * e
    n = network.n
    _lambda = (2 + 2 * _e / 3) * (math.log(comb(n, k)) + l *
                                  math.log(n) + math.log(math.log2(n))) * n / (pow(_e, 2))
    for i in range(1, int(math.log2(n))):
        x = n / pow(2, i)
        theta = _lambda / x
        for i in range(worker_num):
            worker[i].inQ.put(math.ceil((theta - len(R)) / worker_num))
        for sub_worker in worker:
            sub_R = sub_worker.outQ.get()
            R += sub_R
        S, F_R = NodeSelection(R, k)
        if n * F_R >= (1 + _e) * x:
            LB = n * F_R / (1 + _e)
            break
    alpha = math.sqrt(l * math.log(n) + math.log(2))
    beta = math.sqrt((1 - 1 / math.e) *
                     (math.log(comb(n, k)) + l * math.log(n) + math.log(2)))
    lambda_star = 2 * n * pow((1 - 1 / math.e) * alpha + beta, 2) * pow(e, -2)
    theta = lambda_star / LB
    models = {'IC': IC, 'LT': LT}
    while len(R) <= theta:
        R.append(models[model](network, 1)[0])
    return R


def NodeSelection(R, k):
    S = set()
    rr_dict = {}
    for i in range(0, len(R)):
        rr = R[i]
        for u in rr:
            if u not in rr_dict:
                rr_dict[u] = set()
            rr_dict[u].add(i)
    max_heap = list()
    for key, value in rr_dict.items():
        max_heap.append([-len(value), key, 0])
    heapq.heapify(max_heap)
    covered_seeds = set()
    lazy = 0
    while lazy < k:
        val = heapq.heappop(max_heap)
        rr_dict[val[1]] -= covered_seeds
        if lazy == val[2]:
            S.add(val[1])
            lazy += 1
            covered_seeds |= rr_dict[val[1]]
        else:
            val[0] = -len(rr_dict[val[1]])
            val[2] = lazy
            heapq.heappush(max_heap, val)
    return S, len(covered_seeds) / len(R)


def IC(network, theta):
    R = []
    while theta > 0:
        rr_set = set()
        activity_set = set()
        v = random.randint(1, network.n)
        rr_set.add(v)
        activity_set.add(v)
        while activity_set:
            new_activity_set = set()
            for u in activity_set:
                for v in network.adj_list_rev[u]:
                    if v not in rr_set and v not in new_activity_set:
                        if network.adj_mat[v][u] > random.random():
                            new_activity_set.add(v)
            activity_set = new_activity_set
            rr_set = rr_set.union(new_activity_set)
        R.append(rr_set)
        theta -= 1
    return R


def LT(network, theta):
    R = []
    while theta > 0:
        rr_set = set()
        activity_set = set()
        v = random.randint(1, network.n)
        rr_set.add(v)
        activity_set.add(v)
        while activity_set:
            new_activity_set = set()
            for u in activity_set:
                if network.adj_list_rev[u]:
                    v = random.sample(network.adj_list_rev[u], 1)[0]
                    if v not in rr_set and v not in new_activity_set:
                        new_activity_set.add(v)
            activity_set = new_activity_set
            rr_set = rr_set.union(new_activity_set)
        R.append(rr_set)
        theta -= 1
    return R


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', dest='social_network', type=str,
                        default='./NetHEPT.txt')
    parser.add_argument('-k', dest='seed_cnt', type=int,
                        default=5)
    parser.add_argument('-m', dest='diffusion_model',
                        type=str, default='IC')
    parser.add_argument('-t', dest='time_budget', type=int,
                        default=60)
    args = parser.parse_args()
    file_path = args.social_network
    k = args.seed_cnt
    model = args.diffusion_model
    time_budget = args.time_budget

    adj_mat = defaultdict(dict)
    with open(file_path) as f:
        n, m = map(int, f.readline().rstrip('\r\n').split())
        adj_list = [[] for i in range(n + 1)]
        adj_list_rev = [[] for i in range(n + 1)]
        for _ in range(m):
            line = f.readline().rstrip('\r\n').split()
            u, v = map(int, line[0:2])
            w = float(line[2])
            adj_mat[u][v] = w
            adj_list[u].append(v)
            adj_list_rev[v].append(u)
    network = Network(n, m, adj_mat,
                      adj_list, adj_list_rev)

    worker = []
    worker_num = 8
    for i in range(worker_num):
        worker.append(Worker(mp.Queue(), mp.Queue(), model, network))
        worker[i].start()

    seeds = IMM(network, k, 0.3, 1)
    print(*seeds, sep='\n')

    for w in worker:
        w.terminate()
