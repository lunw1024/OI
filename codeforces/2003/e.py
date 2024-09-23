from collections import defaultdict

cache = {}
def search(x: int, mex: dict[int, list[int]]) -> int:
    if x in cache:
        return cache[x]
    if x not in mex:
        return x
    out = max(search(y, mex) for y in mex[x])
    cache[x] = out
    return out

T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    mex = defaultdict(list)
    for i in range(n):
        a = sorted(list(map(int, input().split()))[1:])
        # print(a)
        y = 0
        yy = 0
        cooked = False
        for x in a:
            if x == y:
                y += 1
            elif x > y and not cooked:
                cooked = True
                yy = y
                y += 1
                if x == y:
                    y += 1
            elif x > y and cooked:
                break
        if not cooked:
            yy = y
            y += 1
        assert y > yy
        mex[yy].append(y)

    # establish lb
    source = mex.keys()
    lb = max(source)
    cache.clear()
    for s in source:
        if len(mex[s]) < 2:
            continue # can't start from there.
        lb = max(lb, search(s, mex))
    
    if m <= lb:
        ans = lb * (m + 1)
    else:
        ans = lb * (m + 1) + (m - lb) * (1 + m - lb) // 2

    # adjustments
    for s in source:
        if s > m:
            continue
        orig = max(lb, s)
        new = search(s, mex)
        ans += max(0, new - orig)
        # print('adj by', new - orig, new, orig, s)
        
    print(ans)
        
