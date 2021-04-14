a, b = 3, 2
ans = 0
for i in range(1000):
    a, b = a + 2*b, a + b
    if len(str(a)) > len(str(b)):
        ans += 1
print(ans)
