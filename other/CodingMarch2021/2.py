l, r = map(int, input().split())
ans = 0
for i in [0, 2]:
    for j in [0, 2]:
        for k in [0, 2]:
            for h in [0, 2]:
                if l <= int(str(i) + str(j) + str(k) + str(h)) <= r:
                    ans += 9
print(ans)