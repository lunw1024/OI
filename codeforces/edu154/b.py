t = int(input())
for _ in range(t):
    a = input()
    b = input()
    f = False
    for i in range(len(a) - 1):
        if a[i] == '0' and b[i] == '0' and a[i + 1] == '1' and b[i + 1] == '1':
            f = True
            break
    print("YES" if f else "NO")