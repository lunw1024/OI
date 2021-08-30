
n = int(input())
vowels = set(["A", "E", "I", "O", "U"])
consonants = set(chr(c) for c in range(ord("A"), ord("Z") + 1)) - vowels
f = lambda x: x in vowels
for i in range(1, n + 1):
    s = input()
    a, b = max(s.count(c) for c in vowels), max(s.count(c) for c in consonants)
    arr = list(map(f, s))
    # print(len(arr), arr, a, b)
    a = len(arr) + sum(arr) - a * 2
    b = len(arr) * 2 - sum(arr) - b * 2
    print(f"Case #{i}: {min(a, b)}")

    