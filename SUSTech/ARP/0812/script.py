import sys
import xlsxwriter


def read_file(path):
    items = []
    with open(path, 'r') as sys.stdin:
        while True:
            try:
                items.append(input().split())
            except EOFError:
                break
            for i in range(len(items)):
                items[i][3] = items[i][3].split('/')[-1]
    return items


def write_excel(result):
    workbook = xlsxwriter.Workbook('C:/Users/Hello/Desktop/20200806结果.xlsx')
    worksheet = workbook.add_worksheet()
    for i in range(len(result)):
        worksheet.write(i, 0, result[i][-1])
        worksheet.write(i, 1, result[i][0])
        worksheet.write(i, 2, result[i][1])
        worksheet.write(i, 3, result[i][2])
    workbook.close()


result = read_file('C:/Users/Hello/Desktop/incomplete-results-2338.txt')
write_excel(result)
