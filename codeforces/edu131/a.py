t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    c, d = map(int, input().split())
    ans = 2
    if a == 0 or b == 0 or c == 0 or d == 0:
        ans -= 1
    if a == 0 and b == 0 and c == 0 and d == 0:
        ans -= 1
    print(ans)