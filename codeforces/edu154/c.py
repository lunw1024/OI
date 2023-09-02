t = int(input())
for _ in range(t):
    s = input()
    ones = []
    zeros = []
    cnt = 0
    ans = 'YES'
    for i, x in enumerate(s):
        if x == '+':
            cnt += 1
        elif x == '-':
            cnt -= 1
            while ones and ones[-1] > cnt:
                ones.pop()
                if not ones or ones[-1] != cnt:
                    ones.append(cnt)
            while zeros and zeros[-1] > cnt:
                zeros.pop()
        elif x == '0':
            zeros.append(cnt)
            if cnt <= 1:
                ans = 'NO'
                break
        elif x == '1':
            ones.append(cnt)
        if ones and zeros and ones[-1] >= zeros[0]:
            ans = 'NO'
            break
    print(ans)