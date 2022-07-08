import sys

def err(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

t = int(input())
for _ in range(t):
    # err(f"case {_+1}")
    a, b, c, d = map(int, input().split())
    s = input()
    x = s.count("A")
    y = len(s) - x
    if a + c + d != x or b + c + d != y:
        print("NO")
        continue
    # cut into segments
    p, q, o, ea, eb = 0, 0, 0, [], [] # AB, BA, odd, evenA, evenB
    ch = ""
    i = 0
    while i < len(s):
        if i == 0 or s[i] == s[i - 1]:
            ch = s[i]
            l = 1
            while i < len(s) - 1 and s[i] != s[i + 1]:
                l += 1
                i += 1
            if l == 1:
                pass
            elif l == 2:
                if ch == "A":
                    p += 1
                else:
                    q += 1
            elif l % 2 == 0:
                if ch == "A":
                    ea.append(l // 2)
                else:
                    eb.append(l // 2)
            else:
                o += l // 2

        i += 1
    
    # err(p, q, o, ea, eb)

    c -= p
    d -= q

    c -= o
    for x in ea:
        c -= x
    for x in eb:
        c -= x - 1

    ans = "NO"
    if c <= 0 and d <= 0:
        ans = "YES"

    eb.sort()
    ea.sort(reverse=True)

    while eb:
        k = eb.pop()
        for i in range(k):
            c += 1
            d -= 1
            if c <= 0 and d <= 0:
                ans = "YES"
        d -= 1
        if c <= 0 and d <= 0:
            ans = "YES"
    for i in range(o):
        c += 1
        d -= 1
        if c <= 0 and d <= 0:
            ans = "YES"
    while ea:
        k = ea.pop()
        c += 1
        for i in range(k):
            c += 1
            d -= 1
            if c <= 0 and d <= 0:
                ans = "YES"
    print(ans)

    
