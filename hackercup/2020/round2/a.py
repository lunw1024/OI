import numpy as np

def readints():
    return list(map(int, input().split()))

def expand(l, a, b, c, d, N):
    K = len(l)
    for i in range(N - K):
        l.append((a*l[-2] + b*l[-1] + c) % d)
    return np.array(l)

def solve(N, S: np.ndarray, X: np.ndarray, Y: np.ndarray):
    # check
    if S.sum() < X.sum() or S.sum() > X.sum() + Y.sum():
        return -1
    
    return max(np.maximum(X - S, np.zeros_like(S)).sum(), np.maximum(S - X - Y, np.zeros_like(S)).sum()) 
        

T = int(input())

for t in range(T):
    N, K = readints()
    S = readints()
    a, b, c, d = readints()
    S = expand(S, a, b, c, d, N)
    X = readints()
    a, b, c, d = readints()
    X = expand(X, a, b, c, d, N)
    Y = readints()
    a, b, c, d = readints()
    Y = expand(Y, a, b, c, d, N)

    ans = solve(N, S, X, Y)

    print(f"Case #{t+1}: {ans}")
