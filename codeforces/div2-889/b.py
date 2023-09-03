t = int(input())
for _ in range(t):
    n = int(input())
    ans = 0
    cnt = 0
    for i in range(1, int(1e3)):
        if n % i == 0:
            cnt += 1
        else:
            cnt = 0
        ans = max(ans, cnt)
    print(ans)