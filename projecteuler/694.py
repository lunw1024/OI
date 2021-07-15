import math
from sympy import sieve

n = int(1e18)
p = list(sieve.primerange(2, int(1e6)))

stack = [-1]
ans = 0
x = 1
while True:
    i = len(stack) - 1
    if i < 0:
        break
    if i >= len(p):
        ans += n // x
        stack.pop()
        continue
    if x > n:
        if stack[-1] == -1:
            stack.pop()
            continue
        x //= p[i] ** stack.pop()
        continue
    if stack[i] == -1:
        stack[i] += 1
        stack.append(-1)
        continue
    elif stack[i] == 0:
        stack[i] += 3
        stack.append(-1)
        x *= p[i] ** 3
        continue
    else:
        stack[i] += 1
        stack.append(-1)
        x *= p[i]
        continue
print(ans)
    
