def main():
    n, p, s = list(map(int, input().split()))

    cards = [False for _ in range(n)]
    cards[p-1] = [True]

    for _ in range(s):
        inp = list(map(int, input().split()))

        keep = False
        for i in inp[1:]:
            if cards[i-1]:
                keep = True
                break

        if not keep:
            print("REMOVE")
        else:
            print("KEEP")


if __name__ == "__main__":
    main()
