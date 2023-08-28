t = int(input())
for _ in range(t):
    s = input()
    n = len(s)
    a = '(' * n + ')' * n
    b = '()' * n
    if s in a and s in b:
        print('NO')
    else:
        print('YES')
        if s in a:
            print(b)
        else:
            print(a)