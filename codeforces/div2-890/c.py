t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    ans = max(a)
    for i in range(len(a) - 1):
        l, r = a[i], int(1e9)
        # print('starting with', i)
        while l <= r:
            mid = (l + r) // 2
            need = 0
            # print("testing", mid)
            for j in range(i, n):
                target = mid - (j - i)
                if j == n - 1 and a[j] < target:
                    need = int(1e9)
                    break
                if a[j] >= target:
                    break
                need += target - a[j]
            if need <= k:
                l = mid + 1
                # print('ok')
            else:
                r = mid - 1
                # print('nah')
        # print('best is', r)
        ans = max(ans, r)
    print(ans)
