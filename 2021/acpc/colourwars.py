def main():
    i = input()
    nums = list(map(int, input().split()))

    sorted(nums)

    stud = dict()
    total = 0
    for num in nums:
        if num in stud.keys():
            stud[num]+=1
        else:
            stud[num]=1
        if stud[num] == num + 1:
            total += num + 1
            del stud[num]

    for key in stud.keys():
        total += key + 1
    print(total)

    return

if __name__ == "__main__":
    main()
