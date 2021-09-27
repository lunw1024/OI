# https://projecteuler.net/problem=78
# https://en.wikipedia.org/wiki/Partition_(number_theory)
# https://en.wikipedia.org/wiki/Pentagonal_number_theorem
from tqdm import trange
from icecream import ic

def penta():
    n = 1
    while True:
        yield (3*n - 1) * n // 2
        yield (3*-n - 1) * -n // 2
        n += 1

f = [1, 1]
for n in trange(2, 100000):
    s = 0
    for i, v in enumerate(penta()):
        if n - v < 0:
            break
        # ic(f)
        s += (1 if i % 4 < 2 else -1) * f[n - v]
    # break
    f.append(s)
    if s % 1000000 == 0:
        break

print(len(f) - 1, f[-1])