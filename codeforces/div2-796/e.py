def q(l):
    s = "".join(l)
    print(f"? {s}")
    return int(input())

n, m = map(int, input().split())


l = ["0"] * m
w = [0] * m
for i in range(m):
    l[i] = "1"
    w[i] = q(l)
    l[i] = "0"

idx = list(range(m))
idx.sort(key=lambda x: w[x])
prev = 0
ans = 0
for i in idx:
    l[i] = "1"
    res = q(l)
    if res - prev != w[i]:
        l[i] = "0"
    else:
        prev = res

print("!", prev)

