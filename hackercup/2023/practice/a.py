T = int(input())
for t in range(T):
    s, d, k = map(int, input().split())
    if 2 * s + 2 * d >= k + 1 and s + 2 * d >= k:
        print(f"Case #{t}: YES")
    else:
        print(f"Case #{t}: NO")