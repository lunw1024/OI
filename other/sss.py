import sys

n,m,k = list(map(int,sys.stdin.readline().split()))

s = []
for i in range(m):
    a,b = list(map(int,sys.stdin.readline().split()))
    s.append([a-1,b-1])

lst = [i for i in range(1,n+1)]
c = list(lst)

for i in range(m):
    l = s[i][0]
    r = s[i][1]
    while l<r:
        temp = c[l]
        c[l] = c[r]
        c[r] = temp
        l+=1
        r-=1

d = {}
for i in range(n):
    d[i] = 0

for i in range(n):
    d[c[i]-1] = i

def dfs(x,cnt,c):
    pos[x] = cnt
    l.append(lst[x])
    if d[x]==c:
        return
    dfs(d[x],cnt,c)


pos = [0]*n
cnt = 1
cycle = []
for i in range(n):
    if pos[i] == 0:
        l = []
        dfs(i,cnt,i)
        cnt+=1
        cycle.append(l)

ans = [0]*n
for i in range(n):
    var = len(cycle[pos[i]-1])
    a = cycle[pos[i]-1].index(lst[i])
    ans[i] = cycle[pos[i]-1][(a+k%var)%var]

for i in ans:
    print(i)
            
           

