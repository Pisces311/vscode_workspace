import csv
import numpy as np
import matplotlib.pyplot as plt

alpha = 0.1
beta = 0.3
n = 2000
d = 100
gradient_descent_value = []
backtraking_line_value = []


def gradf(x, Q, b):
    ret = [[] for i in range(d)]
    for i in range(d):
        element = b[i, 0]
        for j in range(d):
            element += Q[i, j] * x[j, 0]
        ret[i].append(element)
    return np.mat(ret)


def f(x, Q, b):
    return (1 / 2 * x.T * Q * x + b.T * x)[0, 0]


def Gradient_descent(x0, Q, b):
    STEP = 3.887e-6
    x = x0
    gradient_descent_value.append(f(x, Q, b))
    for t in range(n):
        x = x - STEP * gradf(x, Q, b)
        gradient_descent_value.append(f(x, Q, b))
    return f(x, Q, b)


def Gradient_descent_with_backtracking_line(x0, Q, b):
    x = x0
    backtraking_line_value.append(f(x, Q, b))
    for t in range(n):
        g = gradf(x, Q, b)
        k = 0
        while True:
            if f(x - beta**k * g, Q, b) <= f(x, Q, b) - alpha * beta**k * np.linalg.norm(g)**2:
                eta = beta**k
                break
            k += 1
        x = x - eta * g
        backtraking_line_value.append(f(x, Q, b))
    return f(x, Q, b)


def plot_line(curve1, curve2):
    plt.figure()
    plt.plot(curve1, 'r-')
    plt.plot(curve2, 'b-')
    plt.legend(['Regular gradient descent',
                'Gradient descent with backtraking line'])
    plt.xlabel('t')
    plt.ylabel('f(x_t)-f(x*)')
    plt.show()


def main():
    x0 = np.mat(np.zeros([100, 1]))
    with open('Piggy/2020Summer_Project/Homework 4/Q.csv', 'r') as Q_file, \
            open('Piggy/2020Summer_Project/Homework 4/b.csv', 'r') as b_file:
        Q = np.mat(list(csv.reader(Q_file)), dtype=float)
        b = np.mat(list(csv.reader(b_file)), dtype=float)
        fmin = min(Gradient_descent(x0, Q, b),
                   Gradient_descent_with_backtracking_line(x0, Q, b))
        gradient_descent_curve = list(map(
            lambda x: x - fmin, gradient_descent_value))
        backtraking_line_curve = list(map(
            lambda x: x - fmin, backtraking_line_value))
        plot_line(gradient_descent_curve, backtraking_line_curve)


if __name__ == "__main__":
    main()
