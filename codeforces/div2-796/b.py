t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    k = 1000
    ans = 0
    for x in a:
        k = min(k, (x & -x).bit_length() - 1)
        if x & 1 == 0:
            ans += 1
    if ans == n:
        ans -= 1
    ans += k
    print(ans)
    

