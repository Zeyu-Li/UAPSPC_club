def r(x: float) -> float:
    # return x ** 2
    # return x ** 0.5
    return 0.5*x if x <= 1/2 else 1.5*x-0.5
    # if x <= 0.5:
    #     return 0.5*x
    # return 1.5*x-0.5

def main():
    # items should be sorted
    items = [1, 3, 4]
    items = [2, 3, 6]
    # items = [4, 6, 7]
    third = 1/3
    # probs = [third] * 3
    # probs = [0.5, 0.4, 0.1]
    probs = [0.4, 0.5, 0.1]

    reu = items[0]
    for i in range(1, len(items)):
        prob = 0
        for j in range(i, len(items)):
            prob += probs[j]
        # print(prob)
        reu += r(prob) * (items[i]-items[i-1])

    

    # for item in items:
    # reu = items[0] + r(1-probs[0]) * (items[1]-items[0]) + r(1-(probs[0]- probs[1])) * (items[2]-items[1])
    # reu = items[0] + r(1-probs[0]) * (items[1]-items[0]) \
    #     + r(1-(probs[0] + probs[1])) * (items[2]-items[1])

    print(reu)
    return

if __name__ == "__main__":
    main()
# 3 1 -1 3 8
# 6 4 0 5 7
# 7 -2 3 10 9
# 4 -1 5 6 5
# -2 -3 3 11 9
# 3 1 5 0 -1
# 2 6 -1 4 -2
# 4 3 2 1 3
# 8 5 6 7 5
# 4 0 3 1 -2