# https://projecteuler.net/problem=61
# search on a layered graph
# abcd = (A, ab) -> {(X, cd) | abcd in X}
# 500 vertices, 50000 edges
# iterate P(6, 6)
from tqdm import tqdm
from itertools import permutations
from icecream import ic

nums = [
    [i*(i+1)//2 for i in range(200)],
    [i*i for i in range(100)],
    [i*(3*i-1)//2 for i in range(100)],
    [i*(2*i-1) for i in range(100)],
    [i*(5*i-3)//2 for i in range(100)],
    [i*(3*i-2) for i in range(100)]
]
# for i in range(6):
#     print(nums[i][:10])
for i in range(6):
    nums[i] = list(filter(lambda x: 1000 <= x <= 9999, nums[i]))

ans = []
def dfs(u, g, p, start) -> bool:
    if g > 6:
        return False
    for v in nums[p[g % 6]]:
        if not str(u)[-2:] == str(v)[:2]:
            continue
        if g == 6 and v == start:
            ans.append(u)
            return True
        elif dfs(v, g + 1, p, start):
            ans.append(u)
            return True
    return False

for p in permutations([0, 1, 2, 3, 4, 5]):
    x = nums[p[0]]
    for g in p:
        # print(p)
        for n in nums[p[0]]:
            if dfs(n, 1, p, n):
                break
        if len(ans) > 0:
            break
    if len(ans) > 0:
        break

print(ans)
print(sum(ans))


