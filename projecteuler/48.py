sum = 0
for i in range (1, 1001):
    sum = i**i + sum
print(str(sum)[-10:])