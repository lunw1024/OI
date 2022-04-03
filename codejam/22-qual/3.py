T = int(input())
for t in range(1, T + 1):
    N = int(input())
    l = list(map(int, input().split()))
    l.sort()
    ans = 0
    for i in l:
        if i > ans:
            ans += 1
    print(f"Case #{t}: {ans}")

