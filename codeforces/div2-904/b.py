T = int(input())
for t in range(T):
    n = int(input())
    a = input()
    # suf = [0] * (n + 1)
    # for i in range(n - 1, -1, -1):
    #     suf[i] = suf[i + 1] + (a[i] == "1")
    # sum = suf[0]
    # for i in range(1, n):
    #     if sum + i > n:
    #         print(-1, end=" ")
    #     else:
    #         print(suf[n - i], end=" ")
    ans = [-1] * (n + 1)
    # print(ans)
    ans[0] = 0
    p = 0
    for i in range(n - 1, -1, -1):
        if a[i] == '0':
            p += 1
            ans[p] = ans[p - 1] + (n - p - i)
    for i in range(1, n + 1):
        print(ans[i], end=" ")
    print()