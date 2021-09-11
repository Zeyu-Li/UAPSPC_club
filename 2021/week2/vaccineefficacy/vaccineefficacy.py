def main():
    cases = int(input())

    # maps a, b, c
    reals = [0 for _ in range(3)]
    fakes = [0 for _ in range(3)]
    vaccine = 0
    for _ in range(cases):
        res = input()
        if res[0] == 'Y':
            vaccine+=1
            if (res[1] == 'Y'):
                reals[0] += 1
            if (res[2] == 'Y'):
                reals[1] += 1
            if (res[3] == 'Y'):
                reals[2] += 1
        else:
            if (res[1] == 'Y'):
                fakes[0] += 1
            if (res[2] == 'Y'):
                fakes[1] += 1
            if (res[3] == 'Y'):
                fakes[2] += 1

    for real, fake in zip(reals, fakes):
        rate_r = real/vaccine
        rate_f = fake/(cases-vaccine)
        if rate_r >= rate_f:
            print("Not effective")
        else:
            # print(real, sum(reals), fake, sum(fakes))
            print((1-rate_r/rate_f)*100)

if __name__ == "__main__":
    main()
