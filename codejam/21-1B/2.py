
def main():
    T = int(input())
    for _ in range(T):
        N, A, B = map(int, input().split())
        U = [0] + list(map(int, input().split()))
        for m in range(N, 500):
            ok = True
            a = [0] * (m + 1)
            a[m] = 1
            for i in range(m, 0, -1):
                if i <= N:
                    if a[i] < U[i]:
                        ok = False
                        break
                    a[i] -= U[i]
                if i - A > 0:
                    a[i - A] += a[i]
                if i - B > 0:
                    a[i - B] += a[i]
                # a[i] = 0
            if ok:
                print(f"Case #{_ + 1}: {m}")
                break
        if not ok:
            print(f"Case #{_ + 1}: IMPOSSIBLE")
        # print(a)

if __name__ == "__main__":
    main()
