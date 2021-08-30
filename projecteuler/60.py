from math import *
from re import L
from sympy import primerange, isprime
from tqdm import tqdm, trange

p = list(primerange(2, int(1e6)))

def f(a, b):
    return isprime(int(str(p[a]) + str(p[b]))) and isprime(int(str(p[b]) + str(p[a])))

def g(a, *params):
    return not all(f(p[a], p[b]) for b in params)

s = int(1e9)


for i in trange(len(p)):
    if i % 1000 == 0:
        print(p[i])
    if p[i] >= s:
        continue
    for j in range(1, i):
        if p[i] + p[j] >= s or g(j, i):
            continue
        for k in range(1, j):
            if p[i] + p[j] + p[k] >= s or g(k, j, i):
                continue
            for l in range(1, k):
                if p[i] + p[j] + p[k] + p[l] >= s or g(l, k, j, i):
                    continue
                for m in range(1, l):
                    if p[i] + p[j] + p[k] + p[l] + p[m] >= s or g(m, l, k, j, i):
                        continue
                    s = min(s, p[i] + p[j] + p[k] + p[l] + p[m])
                    print(s)

print(s)
