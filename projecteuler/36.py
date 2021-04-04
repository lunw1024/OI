def ispalindrome(x):
    l = len(x)
    for i in range(0, l // 2):
        if x[i] != x[l - i - 1]:
            return False
    return True

ans = 0
for i in range(1, 1000001):
    b = f"{i:b}"
    d = f"{i}"
    if ispalindrome(b) and ispalindrome(d):
        ans += i
print(ans) 