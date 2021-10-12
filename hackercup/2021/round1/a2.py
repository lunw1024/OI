M = int(1e9) + 7
T = int(input())
for t in range(1, T + 1):
    n = int(input())
    s = input()
    pre, ans = 0, 0
    l, r, x = 0, 0, 0
    for c in s:
        if c == "X":
            pre += r
            l, r, x = l + r + x + 1, 0, 0
        elif c == "O":
            pre += l
            l, r, x = 0, l + r + x + 1, 0
        else:
            l, r, x = l, r, x + 1
        ans += pre
        ans %= M
        pre %= M
        l %= M
        r %= M
        x %= M
    print(f"Case #{t}: {ans}")
