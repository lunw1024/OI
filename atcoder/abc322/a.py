n = int(input())
s = input()
f = False
for i in range(n - 2):
    if s[i:i+3] == 'ABC':
        print(i + 1)
        f = True
        break
if not f:
    print(-1)
