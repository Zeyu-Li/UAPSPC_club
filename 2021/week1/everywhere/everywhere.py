def main():
    a = int(input())

    for _ in range(a):
        b = int(input())

        places = {}
        for _ in range(b):
            places[input()] = 1

        print(len(places))
    return

if __name__ == "__main__":
    main()
