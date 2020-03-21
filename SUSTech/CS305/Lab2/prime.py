def find_prime(start: int, end: int) -> list:
    lst = []
    for i in range(start, end + 1):
        divide = False
        for j in range(2, i):
            if i % j == 0:
                divide = True
        if i != 1 and not divide:
            lst.append(i)
    return lst
