import sys

input_path = sys.argv[1]
output_path = sys.argv[2]


def is_alphabet(uchar):
    return (uchar >= u'\u0041' and uchar <= u'\u005a') or (uchar >= u'\u0061' and uchar <= u'\u007a')


def count_word(line):
    cnt = 0
    words = line.split()
    for word in words:
        in_word = False
        for i in word:
            if is_alphabet(i):
                if not in_word:
                    cnt += 1
                    in_word = True
            else:
                cnt += 1
                in_word = False
    return cnt


def get_unicode(line):
    return [ord(i) for i in list(line)]


with open(input_path, 'r', encoding='UTF-8') as sys.stdin:
    text = []
    while True:
        try:
            text.append(input())
        except EOFError:
            break
    text.sort(key=lambda x: (count_word(x), get_unicode(x)))

with open(output_path, 'w', encoding='UTF-8') as sys.stdout:
    print(*text, sep='\n')
