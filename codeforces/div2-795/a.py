t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    x = sum(i % 2 == 1 for i in a)
    print(min(x, n - x))

