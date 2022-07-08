t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    a = sorted(list(zip(l, range(n))), reverse=True)
    ans = [0] * (n)
    flag = True
    x = -1
    idx = -1
    for i, v in enumerate(a):
        if v[0] != x:
            if idx != -1:
                ans[idx] = a[i - 1][1]
            idx = v[1]
            x = v[0]
            
        else:
            ans[v[1]] = a[i - 1][1]
    ans[idx] = a[-1][1]
    if any(l[ans[i]] < l[i] or ans[i] == i for i in range(len(ans))):
        print(-1)
    else:
        print(*[i + 1 for i in ans], sep=" ")

