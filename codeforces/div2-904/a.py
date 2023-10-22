T = int(input())
for t in range(T):
    x, k = map(int, input().split())
    for i in range(50):
        y = x + i
        if sum(map(int, list(str(y)))) % k == 0:
            print(y)
            break