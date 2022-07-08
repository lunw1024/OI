t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    if any(x * n == s for x in a):
        print("YES")
    else:
        print("NO")

