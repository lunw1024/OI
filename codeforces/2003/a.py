T = int(input())
for _ in range(T):
    n = int(input())
    s = input()
    print("Yes" if s[0] != s[-1] else "No")
