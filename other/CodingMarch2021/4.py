N, M = map(int, input().split())
s = list(input())
arr = [(int(a), b) for a, b in [input().split() for i in range(N)]]
t = list(input())
cnt = sum(a != b for a, b in zip(s, t))
ans = 0
for a, b in arr:
    if s[a - 1] == t[a - 1]:
        cnt += 1
    elif t[a - 1] == b:
        cnt -= 1
    s[a - 1] = b
    if cnt == 0:
        ans += 1
print(ans)