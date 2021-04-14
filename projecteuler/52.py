for i in range(1, 1000000):
    flag = True
    s = set(str(i))
    for j in range(2, 7):
        if s != set(str(i * j)):
            flag = False
            break
    if flag:
        print(i)
        break
