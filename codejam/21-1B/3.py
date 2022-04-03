from icecream import ic

def greedy(s, x, B) -> int:
    m = min(s)
    for i, c in enumerate(s):
        if c == B:
            continue
        elif c == B - 1:
            if x == 9 or m == B - 1:
                return i
        elif c < B - 1:
            return i
    return -1


def main():
    T, N, B, P = map(int, input().split())
    for t in range(T):
        s = [0] * N
        for i in range(N * B):
            x = int(input())
            # ic(s, x)
            col = greedy(s, x, B)
            # ic(col)
            print(col + 1)
            s[col] += 1
    success = input()


if __name__ == "__main__":
    main()
    

