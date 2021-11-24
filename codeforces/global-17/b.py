
t = int(input())


def check(l, c):
    a, b = 0, n - 1
    while a < b:
        while l[a] == c:
            a += 1
        while l[b] == c:
            b -= 1
        if a < b and l[a] == l[b]:
            a += 1
            b -= 1
        elif a < b and l[a] != l[b]:
            return False
    return True

for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    p, q = 0, n - 1
    palin = True
    while p < q and p < n and q >= 0 and l[p] == l[q]:
        p += 1
        q -= 1
    if p >= q:
        print("YES")
    else:
        print("YES" if check(l, l[p]) or check(l, l[q]) else "NO")
        
        