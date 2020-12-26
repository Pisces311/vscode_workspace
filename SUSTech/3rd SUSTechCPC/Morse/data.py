import sys
from random import choice, randrange

morse = {
    '.-': 'A', '-...': 'B', '-.-.': 'C', '-..': 'D', '.': 'E', '..-.': 'F', '--.': 'G',
    '....': 'H', '..': 'I', '.---': 'J', '-.-': 'K', '.-..': 'L', '--': 'M', '-.': 'N',
    '---': 'O', '.--.': 'P', '--.-': 'Q', '.-.': 'R', '...': 'S', '-': 'T',
    '..-': 'U', '...-': 'V', '.--': 'W', '-..-': 'X', '-.--': 'Y', '--..': 'Z',

    '-----': '0', '.----': '1', '..---': '2', '...--': '3', '....-': '4',
    '.....': '5', '-....': '6', '--...': '7', '---..': '8', '----.': '9',
}

inv = {v: k for k, v in morse.items()}

with open('./In/5.in', 'w') as sys.stdout:
    print(100)
    for _ in range(100):
        n = randrange(50, 1002, 2)
        print(n)
        for i in range(n):
            print(inv[choice('ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789')], end='')
            if i != n - 1:
                print(' ', end='')
            else:
                print('')
