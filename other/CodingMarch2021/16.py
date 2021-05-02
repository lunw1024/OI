N, M = map(int, input().split())
mat = [list(map(int, input().split())) for i in range(N)]
ans = sum(mat[i][j] % 2 == 1 and mat[N - i - 1][j] % 2 == 1 and mat[i][M - j - 1] % 2 == 1 for j in range(M) for i in range(N))
print(ans)