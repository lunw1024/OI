t = int(input())
for _ in range(t):
    n = int(input())
    t = [input() for __ in range(2 * n)]
    s = input()

    c = [0] * 26
    for ch in s:
        c[ord(ch) - ord("a")] += 1
    for i in t:
        for j in i:
            c[ord(j) - ord("a")] += 1
    ans = ""
    for k, v in enumerate(c):
        if v & 1:
            ans = chr(k + ord("a"))
    print(ans)

