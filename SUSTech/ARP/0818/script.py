import sys
import xlsxwriter


def read_file(path):
    items = []
    with open(path, 'r') as sys.stdin:
        while True:
            try:
                a = input()
                if a[0] == '/':
                    items.append([a.split('/')[-1], input()])
            except EOFError:
                break
    return items


def write_excel(result):
    workbook = xlsxwriter.Workbook('C:/Users/Hello/Desktop/20200818结果.xlsx')
    worksheet = workbook.add_worksheet()
    for i in range(len(result)):
        worksheet.write(i + 1, 0, result[i][0])
        worksheet.write(i + 1, 1, result[i][1])
    workbook.close()


result = read_file('./SUSTech/ARP/0818/compat-0813.txt')
write_excel(result)
