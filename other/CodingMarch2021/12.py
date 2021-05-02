N, K, X = map(int, input().split())
print(max(0, X - K - 1) + max(0, N - (X + K)))