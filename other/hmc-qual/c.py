l = ['@', '8', '(', '|)', '3', '#', '6', '[-]', '|', '_|', '|<', '1', '[]\\/[]', '[]\\[]', '0', '|D', '(,)', '|Z', '$', "']['", '|_|', '\\/', '\\/\\/', '}{', '`/', '2']
d = {i : x for (i, x) in zip([chr(ord('a') + j) for j in range(26)], l)}
s = input().lower()
out = []
for c in s:
    if c in d:
        out.append(d[c])
    else:
        out.append(c)
print("".join(out))
