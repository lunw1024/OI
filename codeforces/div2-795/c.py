t = int(input())

def f(s):
    s = "".join(s)
    out = 0
    for i in range(len(s) - 1):
        out += int(s[i:i+2])
    if s == "1":
        out = 1
    return out

for _ in range(t):
    n, k = map(int, input().split())
    s = list(input())
    low = -1
    for i in range(n - 1, -1, -1):
        if s[i] == "1":
            low = i
            break
    if low == -1 or low == n - 1 or n - low - 1 > k:
        pass
    else:
        s[low], s[n - 1] = s[n - 1], s[low]
        k -= n - low - 1

    high = -1
    for i in range(n):
        if s[i] == "1":
            high = i
            break
    if high == -1 or high == 0 or high == n - 1 or high > k:
        pass
    else:
        s[high], s[0] = s[0], s[high]

    print(f(s))
            
