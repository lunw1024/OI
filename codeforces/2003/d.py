T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    mex = 0
    for i in range(n):
        a = sorted(list(map(int, input().split()))[1:])
        # print(a)
        y = 0
        cooked = False
        for x in a:
            if x == y:
                y += 1
            elif x > y and not cooked:
                cooked = True
                y += 1
                if x == y:
                    y += 1
            elif x > y and cooked:
                break
        mex = max(y + (not cooked), mex)
    if m <= mex:
        ans = mex * (m + 1)
    else:
        ans = mex * (m + 1) + (m - mex) * (1 + m - mex) // 2
    print(ans)
        
