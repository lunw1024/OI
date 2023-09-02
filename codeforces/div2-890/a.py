t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    ans = 0
    for i in range(len(l) - 1):
        if l[i] > l[i + 1]:
            ans = max(ans, l[i])
    print(ans)