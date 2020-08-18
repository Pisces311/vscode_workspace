import sympy


def C1(Pg1):
    return 0.1 * Pg1**2 + 15 * Pg1


def C2(Pg2):
    return 0.075 * Pg2**2 + 30 * Pg2


def C3(Pg3):
    return 0.15 * Pg3**2 + 25 * Pg3


def cons1(Pg1, PD1, theta2, theta3, x12, x13):
    return -Pg1 + PD1 - theta2 / x12 - theta3 / x13


def cons2(Pg2, PD2, theta2, theta3, x12, x13):
    return -Pg2 + PD2 + theta2 / x12 + (theta2 - theta3) / x13


def cons3(Pg3, PD3, theta2, theta3, x23):
    return -Pg3 + PD3 + (theta3 - theta2) / x23 + theta3 / x23


def main():
    x12, x13, x23 = 0.1, 0.1, 0.1

    # var = (Pg1, Pg2, Pg3, theta2, theta3, lambda1, lambda2, lambda3, mu1, PD1, PD2, PD3)
    var = sympy.symbols('Pg1:4, theta2:4, lambda1:4, mu1, PD1:4')
    L = C1(var[0]) + C2(var[1]) + C3(var[2]) + \
        var[5] * cons1(var[0], var[9], var[3], var[4], x12, x13) + \
        var[6] * cons2(var[1], var[10], var[3], var[4], x12, x13) + \
        var[7] * cons3(var[2], var[11], var[3], var[4], x23) + \
        var[8] * (-var[3] / x12 - 50)

    eqs = []
    for i in range(9):
        dL = sympy.diff(L, var[i])
        # print(dL)
        eqs.append(dL.subs({var[-3]: 0, var[-2]: 0, var[-1]: 0}))
    ans = sympy.solve(eqs, var)
    for i in range(9):
        print(var[i], round(ans[var[i]], 2))


if __name__ == "__main__":
    main()
