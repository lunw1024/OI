N = int(input())
arr = list(map(int, input().split()))
sum = 0
reward = {}
reward[arr[0]] = 1
prev = -1
for i in range(1, N):
    if arr[i] not in reward:
        reward[arr[i]] = 0
    if arr[i - 1] == arr[i]:
        continue
    reward[arr[i]] += 1
    sum += 1
    if prev == arr[i]:
        reward[arr[i - 1]] += 1
    prev = arr[i - 1]
ans = max(0, min(sum - re for re in reward.values()))
print(ans)