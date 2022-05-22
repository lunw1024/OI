
def guess(s):
    print(f"? {s}", flush=True)
    res = input()
    if res == "22222":
        quit()
    return res

lec = "abcdefghijklmnopqrstuvwxyz"
# stage 1
chars = []
for i in range(0, 25, 5):
    res = guess(lec[i:i+5])
    for j in range(5):
        if res[j] in ["1", "2"]:
            chars.append(lec[i + j])
while len(chars) < 5:
    chars.append("z")

# stage 2
ans = ["?"] * 5
for i in range(4):
    res = guess(chars[i] * 5)
    idx = res.index("2")
    ans[idx] = chars[i];
ans[ans.index("?")] = chars[-1]
guess("".join(ans))

