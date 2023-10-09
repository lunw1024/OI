T = int(input())
for t in range(T):
    n = int(input())
    if n % 3 != 0:
        if n - 3 == 1 or n - 3 == 2 or n - 3 < 1:
            print("NO")
        else:
            print("YES")
            print(1, 2, n - 3)
    else:
        if n - 5 == 1 or n - 5 == 4 or n - 5 < 1:
            print("NO")
        else:
            print("YES")
            print(1, 4, n - 5)