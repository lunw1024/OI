N, M = map(int, input().split())
mat = [list(map(int, list(input()))) for i in range(N)]
ans = 0
for j in range(M):
    ans += sum(mat[i][j] == 2 for i in range(N))
    for i in range(N - 1, -1, -1):
        if mat[i][j] == 1:
            break
        if mat[i][j] == 2:
            ans -= 1
            break
print(ans)
