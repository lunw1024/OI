# a^2 + b^2 = (p - a - b)^2
# 0 = p^2 + 2ab - 2pa - 2pb
# 2(p - a)(p - b) = p^2
# (2 + sqrt(2)) * a = p
import math
from tqdm import trange

mx, argmax = 0, 1
for p in trange(120, 1001):
    amax = math.ceil(p / (2 + math.sqrt(2)))
    cnt = 0
    for a in range(1, amax + 1):
        b = p - p**2 / 2 / (p - a)
        if b % 1 == 0:
            cnt += 1
    if cnt > mx:
        mx, argmax = cnt, p
print()
print(mx, argmax)
    