
sum = [0]
N = int(input())

sum.extend(map(int, input().split()))
for i in range(1, N + 1):
    sum[i] += sum[i - 1]

ans = 0
p = 1
for i in range(1, N - 1):
    target = (sum[N] - sum[i]) / 2

    while abs(sum[p] - sum[i] - target) > abs(sum[p + 1] - sum[i] - target):
        p += 1

    ans = max(ans, sum[i] * (sum[p] - sum[i]) * (sum[N] - sum[p]))

print(ans)

