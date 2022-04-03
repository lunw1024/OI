T = int(input())
for t in range(1, T + 1):
    tup = list(map(int, input().split()))
    tup = [min(a, b) for a, b in zip(tup, list(map(int, input().split())))]
    tup = [min(a, b) for a, b in zip(tup, list(map(int, input().split())))]

    if sum(tup) < int(1e6):
        print(f"Case #{t}: IMPOSSIBLE")
    else:
        s = int(1e6)
        print(f"Case #{t}: ", end="")
        for i, c in enumerate(tup):
            print(min(s, c), end=" " if i < 3 else "\n")
            s -= min(s, c)

