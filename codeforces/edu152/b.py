t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(lambda x: int(x) % k, input().split()))
    l = [(a[i] if a[i] > 0 else k, -(i+1)) for i in range(n)]
    l = sorted(l, reverse=True)
    print(" ".join([str(-x[1]) for x in l]))