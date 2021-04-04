import math
x = int(input())
# print(math.floor(x ** (1/2)))

ans = 0
while True:
    while x > 0:
        ans += x % 10
        x //= 10
    if ans > 9:
        ans, x = 0, ans
    else:
        break
print(ans)
