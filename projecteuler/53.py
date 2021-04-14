from sympy import binomial
ans = 0
for n in range(1, 101):
    for r in range(1, n + 1):
        if binomial(n, r) > 1e6:
            ans += 1
print(ans)
