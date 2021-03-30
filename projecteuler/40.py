from functools import reduce
import math
l = []
i = 0
size = 0
while size <= 1000000:
    l.append(str(i))
    i += 1
    size += math.floor(math.log(i, 10))
s = "".join(l)
print(len(s))
print(reduce(lambda x, y: int(x) * int(y), [s[10**i] for i in range(7)]))