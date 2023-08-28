n, d = map(int, input().split())
mask = [True] * d
for i in range(n):
    s = input()
    for j in range(len(s)):
        if s[j] == 'x':
            mask[j] = False
ans = [0] * d
for i in range(d):
    if mask[i]:
        ans[i] = 1
    if i > 0 and mask[i]:
        ans[i] += ans[i - 1]
print(max(ans))