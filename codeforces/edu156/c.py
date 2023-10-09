from collections import deque
T = int(input())
for t in range(T):
    s = input()
    pos = int(input())
    l, r = deque(), deque(s)
    ans = ""
    while len(r) + len(l) >= 1:
        if pos <= len(l) + len(r):
            ans = l[pos - 1] if pos <= len(l) else r[pos - len(l) - 1]
            break
        else:
            pos -= len(l) + len(r)
        while len(r) > 0 and (len(l) == 0 or l[-1] <= r[0]):
            l.append(r.popleft())
        # print(l, r)
        if len(l) > 0:
            l.pop()
        else:
            while True:
                continue
            
    print(ans, end="")