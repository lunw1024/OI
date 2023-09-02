t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    d = 0
    for x in l:
        if x == 1:
            d -= 1
        else:
            d += x - 1
    ok = not n == 1 and d >= 0
    print("YES" if ok else "NO")
        