n, m = map(int, input().split())
a = [[x, i + 1] for i, x in enumerate(map(int, input().split()))]
b = [[x, i] for i, x in enumerate(map(int, input().split()))]
a.sort(reverse=True)
b.sort(reverse=True)
# print(a, b)
ans = [[] for _ in range(m)]
l = -1
for r in range(n):
    for j, (x, i) in enumerate(b):
        if x == -1:
            continue
        # print(l, r)
        if x <= a[r][0] * (r - l):
            b[j][0] = -1
            ans[i] = [i for x, i in a[l+1:r+1]]
            print(i, a[l+1:r+1])
            l = r
            break
ok = True
# print(ans)
for x in ans:
    if not x:
        ok = False
        break
if not ok:
    print("NO")
else:
    print("YES")
    for x in ans:
        print(len(x), " ".join(map(str, x)))
