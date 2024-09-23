from functools import cache
import math
@cache
def g(x):
    if x == 0:
        return 0
    s = set()
    for i in range(x):
        if math.gcd(i, x) == 1:
            s.add(g(i))
    mex = 0
    while mex in s:
        mex += 1
    return mex

if __name__ == "__main__":
    for i in range(130):
        print(i, g(i))
