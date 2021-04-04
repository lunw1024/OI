
H, W = map(int, input().split())
cake = [[False] * W for i in range(H)]
for i in range(H):
    s = input()
    for j in range(W):
        if s[j] == '*':
            cake[i][j] = True

x, y = 0, 0
ans = 0
while x < H and y < W:
    if cake[x][y]:
        ans += 1
    if y < W - 1 and cake[x][y+1]:
        y += 1
        continue
    if x < H - 1 and cake[x+1][y]:
        x += 1
        continue
    
    if y < W - 1:
        y += 1
        continue
    elif x < H - 1:
        x += 1
        continue

    if x == H - 1 and y == W - 1:
        break

print(ans)
