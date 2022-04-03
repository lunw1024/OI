
def solve(R, C):
    for i in range(R * 2 + 1):
        if i == 0:
            print("." * 2 + "+-" * (C - 1) + "+")
        elif i == 1:
            print("." * 2 + "|." * (C - 1) + "|")
        elif i % 2 == 0:
            print("+-" * C + "+")
        else:
            print("|." * C + "|")

if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        R, C = map(int, input().split())
        print(f"Case #{t}: ")
        solve(R, C)
