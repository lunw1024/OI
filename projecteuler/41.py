from sympy.ntheory import isprime
from tqdm import trange

def is_pandigital(x):
    return "0" not in str(x) and len(set(list(str(x)))) == len(str(x)) and int(max(str(x))) == len(str(x))

ans = 0
for i in trange(7654321, 1, -1):
    if is_pandigital(i) and isprime(i):
        ans = max(ans, i)
print(ans)