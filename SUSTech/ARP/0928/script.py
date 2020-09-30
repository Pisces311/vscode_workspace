import sys
import pandas as pd


def read_file(path):
    items = []
    with open(path, 'r') as sys.stdin:
        while True:
            try:
                line = input().split()
                line[-1] = line[-1].split('/')[-1]
                items.append(line)
            except EOFError:
                break
    return items


def write_excel(result):
    df = pd.DataFrame(result)
    df.to_excel('aaa.xlsx', index=False)


result = read_file('E:/SUSTech/ARP/20200928/aaa.txt')
write_excel(result)
