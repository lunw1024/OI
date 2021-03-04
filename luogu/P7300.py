import string

N, Q = [int(a) for a in input().split()]
alphabet = {c: i+1 for i, c in enumerate(string.ascii_uppercase)}
fence = [0] + [alphabet[c] for c in input()] + [0]
vis = [False] * 27
pre = [0] * (N + 2)
suf = [0] * (N + 2)

for i in range(1, N + 1):
    if fence[i] > fence[i - 1]:
        pre[i] = pre[i - 1] + 1
    elif fence[i] <= fence[i - 1]:
        pre[i] = pre[i - 1] + (not vis[fence[i]])
        for j in range(fence[i - 1], fence[i], -1):
            vis[j] = False
    vis[fence[i]] = True

vis = [False] * 27

for i in range(N, 0, -1):
    if fence[i] > fence[i + 1]:
        suf[i] = suf[i + 1] + 1
    elif fence[i] <= fence[i + 1]:
        suf[i] = suf[i + 1] + (not vis[fence[i]])
        for j in range(fence[i + 1], fence[i], -1):
            vis[j] = False
    vis[fence[i]] = True

for i in range(Q):
    l, r = [int(a) for a in input().split()]
    print(pre[l - 1] + suf[r + 1])
