n = int(input())
a = list(map(int, input().split()))
cnt = [0] * n

l = [0]
cnt[0] += 1
while cnt[l[-1]] != 2:
    l.append(a[l[-1]] - 1)
    cnt[l[-1]] += 1

x = l[-1]
cyc = l[l.index(x)+1:]
print(len(cyc))
print(" ".join(map(lambda x: str(x + 1), cyc)))
