t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = input()
    b = input()
    if n == m:
        print("YES" if a == b else "NO")
        continue
    if m == 1:
        print("YES" if b in a else "NO")
        continue

    # print("debug:", b[1:], a[-m + 1:], b[0], a[:-m + 1])
    if b[1:] == a[-m+1:] and b[0] in a[:-m+1]:
        print("YES")
    else:
        print("NO")