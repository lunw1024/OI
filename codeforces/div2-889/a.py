t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    ans = 0
    for i, x in enumerate(l):
        if i + 1 == x:
            ans += 1
    print((ans + 1) // 2)