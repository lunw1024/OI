import math
T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    print(a[math.ceil((n - 1) / 2)])
