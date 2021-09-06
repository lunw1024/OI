# https://projecteuler.net/problem=66
from sympy.ntheory.primetest import is_square
from tqdm import trange
from icecream import ic
from math import sqrt
INF = int(1e9)
ans = 1
maximum = 0

# https://en.wikipedia.org/wiki/Pell%27s_equation
def check(l, d):
    if len(l) == 0:
        return False
    a, b = 1, 0
    for i in l[::-1]:
        a, b = b, a + i * b
    # a/b is the rational approximation
    ic(a, b)
    if a * a - d * b * b == 1:
        global maximum, ans
        if maximum < a:
            maximum = a
            ans = d
        return True
    return False

for d in trange(2, 1001):
    if is_square(d):
        continue
    # chakravala
    a, b, k = 1, 0, 1
    m = 1
    while k != 1 or b == 0:
        # best m
        m = k * (m // k + 1) - m
        m = m - int((m - sqrt(d)) / k) * k

        # iterate
        a, b = (a*m + d*b) // abs(k), (a + b*m) // abs(k)
        k = (m*m - d) // k
        # ic(a, b, k, m)
    if maximum < a:
        maximum = a
        ans = d


print(ans)
