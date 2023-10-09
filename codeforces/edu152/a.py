t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    print(min(a * 2 - 1, (b + c) * 2 + 1))