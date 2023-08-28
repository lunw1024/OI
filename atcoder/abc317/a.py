n, h, x = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
while h + a[ans] < x:
    ans += 1
print(ans + 1)