from tqdm import tqdm
from sympy import isprime, primerange

def replace(x, digit, mask):
    assert type(x) is str
    assert type(digit) is str and len(digit) == 1
    x, mask = list(x), list(mask)
    l = len(x)
    assert len(mask) == l
    for i in range(l):
        if mask[i] == '1':
            x[i] = digit
    return "".join(x)

def validate(x, mask):
    d = None
    for i in range(len(x)):
        if d is None and mask[i] == '1':
            d = x[i]
        if mask[i] == '1' and d != x[i]:
            return False
    return True

ans = 0
for i in tqdm(primerange(10, 200000)):
    i = str(i)
    l = len(i)
    for mask in range(2**l):
        mask = f"{mask:b}".zfill(l)
        if not validate(i, mask):
            continue
        count = 0
        for j in range(10):
            new = replace(i, str(j), mask)
            if new[0] != '0' and isprime(int(new)):
                count += 1
        if count == 8:
            ans = i
            break
    if ans != 0:
        break
print(ans)
