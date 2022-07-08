t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(list(map(int, input().split())))
    if n % 2 == 1:
        print("NO")
        continue
    if a[n // 2 - 1] < a[n // 2]:
        flag = True
    elif a.count(a[n // 2]) < n // 2:
        flag = True
    else:
        flag = False
    if flag:
        print("YES")
        for i in range(n // 2):
            print(a[i], a[i + n // 2], sep=" ", end=" " if i < n // 2 - 1 else "\n")
    else:
        print("NO")

