n, m, x, y = map(int, input().split())
print((n // x) * (m // x), (n * m - (n // x * x) * (m // x * x)) // y**2)