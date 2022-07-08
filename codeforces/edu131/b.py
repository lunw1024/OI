t = int(input())
for _ in range(t):
    n = int(input())
    print(2)
    vis = [False] * (n + 1)
    ans = []
    for i in range(1, n + 1):
        if vis[i]:
            continue
        ans.append(i)
        vis[i] = True
        a = i * 2
        while a <= n and not vis[a]:
            ans.append(a)
            vis[a] = True
            a *= 2
    print(" ".join(map(str, ans)))
        