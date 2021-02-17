N = int(input())
inc = list(map(int, input().split()))
outc = list(map(int, input().split()))
inc = [a - 1 for a in inc]
outc = [a - 1 for a in outc]
p = 0
ans = 0
vis = [False] * N
for b in outc:
    if b != inc[p]:
        ans += 1
    vis[b] = True
    while p < N and vis[inc[p]]:
        p += 1
print(ans)
