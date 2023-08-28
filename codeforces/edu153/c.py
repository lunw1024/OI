T = int(input())
for _ in range(T):
    n = int(input())
    p = list(map(int, input().split()))
    ans = 0
    x, y = p[0], int(1e9)
    for i, v in enumerate(p):
        if v < x:
            x = v
        elif x < v < y:
            ans += 1
            y = v

    print(ans)