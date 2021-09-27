from multiset import Multiset
from icecream import ic
from tqdm import trange

T = int(input())
for t in range(T):
    N, M = map(int, input().split())
    ans = 0
    s = Multiset(map(int, input().split()))
    b = s
    c = Multiset()
    for i in trange(N):
        s1 = Multiset(map(int, input().split()))
        ans += len(s - s1)
        c += s - s1
        c &= b
        s = s1
    ans -= len(b & c)
    # ic(b & c)
    print(f"Case #{t + 1}: {ans}")
