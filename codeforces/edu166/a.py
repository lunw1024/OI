T = int(input())
for _ in range(T):
    n = int(input())
    s = input()
    lets = [c for c in s if c.islower()]
    nums = [c for c in s if c.isnumeric()]
    ok = True
    ok = lets == sorted(lets) and nums == sorted(nums)
    for i in range(n - 1):
        if s[i].islower() and s[i + 1].isnumeric():
            ok = False
    print("YES" if ok else "NO")
