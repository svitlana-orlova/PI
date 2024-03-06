# Found at:
# https://gist.github.com/deeplook/4947835#file-pi_digits-py
#
def lamberts_pi():
    k, a, b, a1, b1 = 2, 4, 1, 12, 4
    while True:
        p, q, k = k * k, 2 * k + 1, k + 1
        a, b, a1, b1 = a1, b1, p * a + q * a1, p * b + q * b1
        d, d1 = a / b, a1 / b1
        while d == d1:
            yield int(d)
            a, a1 = 10 * (a % b), 10 * (a1 % b1)
            d, d1 = a / b, a1 / b1

pi = lamberts_pi()
nums = [next(pi) for _ in range(1000)]

