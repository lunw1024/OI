import math
import heapq

T = int(input())
for _ in range(T):
    n = int(input())
    a = list({x * y for x in range(1, n + 1) for y in range(1, n + 1)})
    ans = 0
    for m in a:
        cur = 1
        l = []
        g = -m
        for i in range(n, 0, -1):
            while cur <= n and cur * i <= m:
                l.append(cur)
                cur += 1
            if not l:
                g = 0
                break
            g += i * l.pop()
        ans = max(ans, g)
    print(ans)

