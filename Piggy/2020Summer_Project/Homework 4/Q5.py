import csv
import numpy as np
from scipy.optimize import minimize


def f(x):
    mat = [[]for i in range(20)]
    for i in range(20):
        mat[i].append(x[i])
    mat = np.mat(mat)
    return np.linalg.norm(A * mat - b, ord=1)


with open('Piggy/2020Summer_Project/Homework 4/A_40_20.csv', 'r') as A_file, \
        open('Piggy/2020Summer_Project/Homework 4/b_40.csv', 'r') as b_file:
    A = np.mat(list(csv.reader(A_file)), dtype=float)
    b = np.mat(list(csv.reader(b_file)), dtype=float)
    cons = ({'type': 'eq', 'fun': lambda x: sum(x) - 1})
    bnds = tuple([(0, 1)for i in range(20)])
    x0 = [1 if not i else 0 for i in range(20)]
    res = minimize(f, x0, bounds=bnds, constraints=cons)
    print(res)
