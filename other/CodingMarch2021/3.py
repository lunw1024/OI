N = int(input())
arr = [tuple(map(int, input().split())) for i in range(N * N)]
ans = [0] * (N + 1)
p = 1
for (a, b) in arr:
    if a == b:
        p = a
        ans[p] += 1
        p = p % N + 1
        continue
    while a == p or b == p:
        p = p % N + 1
    ans[p] += 1
    p = p % N + 1
print(" ".join(str(i) for i in ans[1:]))