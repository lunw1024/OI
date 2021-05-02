from collections import Counter
N = int(input())
i = 0
ss = {}
ans = 0
while i * i <= N:
    s = tuple(sorted(Counter(str(i * i)).items()))
    # print(s)
    if s in ss:
        ans += ss[s]
        ss[s] += 1
    else:
        ss[s] = 1
    i += 1
print(ans)