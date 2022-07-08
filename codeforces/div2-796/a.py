t = int(input())
for _ in range(t):
    x = int(input())
    ans = x & (-x)
    if ans ^ x == 0:
        if ans == 1:
            ans |= 2
        else:
            ans |= 1
    print(ans)
