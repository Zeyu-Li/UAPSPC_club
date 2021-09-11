def main():
    cases = int(input())

    times = []
    for _ in range(cases):
        times.append(int(input()))

    stopped = True
    run = 0
    last = 0
    for time in times:
        if not stopped:
            run+=time-last
        last = time
        stopped = not stopped

    if not stopped:
        print("still running")
    else:
        print(run)

    return

if __name__ == "__main__":
    main()
