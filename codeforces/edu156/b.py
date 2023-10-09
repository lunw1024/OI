T = int(input())

def d(x, y):
    return (x[0] - y[0])**2 + (x[1] - y[1])**2

for t in range(T):
    P = tuple(map(int, input().split()))
    A = tuple(map(int, input().split()))
    B = tuple(map(int, input().split()))
    O = (0, 0)
    ans = min(max(d(A, O), d(A, P)), max(d(B, O), d(B, P)), max(d(A, O), d(B, P), d(A, B) / 4), max(d(A, P), d(B, O), d(A, B) / 4))
    print(ans ** (1/2))
