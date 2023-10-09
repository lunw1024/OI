t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    s = input()
    x, y = [n] * n, [-1] * n
    x[n - 1] = n - 1 if s[n - 1] == '1' else n
    for i in range(n - 2, -1, -1):
        x[i] = i if s[i] == '1' else x[i + 1]
    y[0] = 0 if s[0] == '0' else -1
    for i in range(1, n):
        y[i] = i if s[i] == '0' else y[i - 1]
    q = []
    for i in range(m):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        if x[l] > y[r]:
            q.append((-1, -1))
        else:
            q.append((x[l], y[r]))
    print(len(set(q)))
    
