T = int(input())
for t in range(1, T + 1):
    n = int(input())
    s = list(filter(lambda c: c != "F", input()))
    # print(s)
    ans = 0
    for i in range(1, len(s)):
        if s[i - 1] != s[i]:
            ans += 1
    print(f"Case #{t}: {ans}")
