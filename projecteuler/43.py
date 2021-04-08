from tqdm import tqdm
from itertools import permutations
ans = 0
for s in tqdm(permutations("0123456789")):
    s = "".join(s)
    if s[0] == '0':
        continue
    if (int(s[1:4]) % 2 == 0 and
        int(s[2:5]) % 3 == 0 and
        int(s[3:6]) % 5 == 0 and
        int(s[4:7]) % 7 == 0 and
        int(s[5:8]) % 11 == 0 and
        int(s[6:9]) % 13 == 0 and
        int(s[7:10]) % 17 == 0):
        ans += int(s)
print(ans)
