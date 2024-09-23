from collections import Counter
T = int(input())
for _ in range(T):
    n = int(input())
    s = Counter(input())
    chars = set(s.keys())
    ans = []
    while chars:
        for c in chars:
            if s[c] > 0:
                ans.append(c)
                s[c] -= 1
        for c in chars.copy():
            if s[c] == 0:
                chars.remove(c)
    print("".join(ans))
    
    
