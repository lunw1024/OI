def v(x):
    return ord(x) - ord("A")

s = input()
ans = "YES"
for i in range(2, len(s)):
    if v(s[i]) != (v(s[i-1]) + v(s[i-2])) % 26:
        ans = "NO"
        break
print(ans)
