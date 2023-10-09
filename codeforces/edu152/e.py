n = int(input())
minstk, maxstk = [(0, -1)], [(int(1e9), -1)] # (value, i)
stk = [(0, -1)] # (cnt, i)
cnt = 0
ans = 0
l = map(int, input().split())
for i, x in enumerate(l):
    while minstk[-1][0] > x:
        minstk.pop()
    while maxstk[-1][0] < x:
        maxstk.pop()
    while stk[-1][1] > min(minstk[-1][1], maxstk[-1][1]):
        e = stk.pop()
        cnt -= e[0]
    a, b = minstk[-1][1], maxstk[-1][1]
    m = stk[-1][1]
    if a > b:
        stk.append((a - b - (m - b if m > b else 0), a))
        cnt += a - b
    minstk.append((x, i))
    maxstk.append((x, i))
    ans += cnt
print(ans)
    
        