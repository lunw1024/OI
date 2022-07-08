import math
import random
# import numpy as np
from queue import PriorityQueue

t = int(input())
# n = int(input())
for _ in range(t):
    n = int(input())
    b = list(map(int, input().split()))
    # p = np.random.permutation(list(range(1, n + 1)))
    # b = [math.floor((i + 1) / x) for i, x in enumerate(p)]

    arr = [[] for __ in range(n + 1)]
    for i, x in enumerate(b):
        if x == 0:
            l, r = i + 2, n
        else:
            l = math.ceil((i + 1) / (x + 1)) + ((i + 1) % (x + 1) == 0)
            r = math.floor((i + 1) / x)
        arr[l].append((l, r, i))
        # print("debug: ", (l, r, i))
    ans = [0] * n
    head = 1
    q = PriorityQueue()
    while head <= n:
        for x in arr[head]:
            l, r, i = x
            q.put((r, l, i))
            # print(f"putting {(l, r, i)}")

        top = q.get()
        r, l, i = top
        ans[i] = head
        # print(f"{head} -> {(l, r, i)}")
        head += 1
    print(" ".join(map(str, ans)))

    # if not all((i + 1) // a == b[i] for i, a in enumerate(ans)):
    #     print("failed on", b)
