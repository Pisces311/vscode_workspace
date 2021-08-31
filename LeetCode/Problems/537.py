class Solution:
    def parse(self, num: str) -> tuple:
        a = num.split('+')
        return int(a[0]), int(a[1][:-1])

    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        real1, img1 = self.parse(num1)
        real2, img2 = self.parse(num2)
        real3 = real1 * real2 - img1 * img2
        img3 = real1 * img2 + real2 * img1
        return str(real3) + '+' + str(img3) + 'i'