import random
from itertools import permutations
T = 20
N = 5
with open("in.txt", "w") as f:
    with open("ans.txt", "w") as out:
        f.write(str(T) + "\n")
        for _ in range(T):
            a = [random.randint(1, N) for __ in range(N)]
            f.write(str(N) + "\n")
            f.write(" ".join(map(str, a)) + "\n")
                
            # solve
            arr = [(x, i) for i, x in enumerate(a)]
            ans = False
            for p in permutations(range(1, N + 1)):
                for q in permutations(range(1, N + 1)):
                    # print(p, q)
                    # print([max(x, y) for x, y in zip(p, q)], a)
                    if [max(x, y) for x, y in zip(p, q)] == a:
                        ans = True
                        break
                    if ans:
                        break
            if ans:
                out.write("YES\n")
            else:
                out.write("NO\n")