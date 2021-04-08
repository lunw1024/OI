from tqdm import trange
from sympy import isprime
from math import sqrt
ans = 0
for i in trange(1000, 10000):
    if i % 2 == 1 and not isprime(i):
        if not any([isprime(i - 2*j*j) for j in range(1, int(sqrt(i / 2)) + 1)]):
            ans = i
            break
print(ans)
