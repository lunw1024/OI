

T = int(input())
for _ in range(T):
    N = int(input())
    l, r = [], []
    for i in range(N):
        a, b = map(int, input().split())
        l.append(a)
        r.append(b)
    
    dp = [0] * (N + 1)
    for i in range(1, N + 1):

