def rollingSum(x):
    # from geeksforgeeks 😳
    res = 0
    sum_ = 0
    for index, item in enumerate(x):
        res += item * index - sum_
        sum_ += item

    return res

def main():
    cases = int(input())

    x = []
    y = []

    for _ in range(cases):
        a,b = map(int, input().split())
        x.append(a)
        y.append(b)

    x.sort()
    y.sort()

    print(rollingSum(x)+rollingSum(y))

    return

if __name__ == "__main__":
    main()
