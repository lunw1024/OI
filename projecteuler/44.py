from tqdm import tqdm
ans = 1e9
l = [int(i * (3*i-1) / 2) for i in range(1, 10001)]
s = set(l)
for i in range(10000):
    for j in range(i - 1):
        if l[i] + l[j] in s and l[i] - l[j] in s:
            ans = min(ans, l[i] - l[j])
            # print(f"find {l[i]} {l[j]}")
print(ans)
