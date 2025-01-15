n = int(input())
a = list(map(int, input().split()))
base = 1
while len(a) > 1:
    b = []
    p = 0
    while p < len(a):
        if p + 1 < len(a) and a[p] == a[p + 1] and a[p] == base:
            b.append(base * 2)
            p += 2
        elif a[p] == base:
            p += 1
        else:
            b.append(a[p])
            p += 1
    base *= 2
    # print(base)
    # print(a)
    a = b
print(a[0])
        
