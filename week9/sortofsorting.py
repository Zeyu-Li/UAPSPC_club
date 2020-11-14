while (1):
    cases = int(input())
    if cases == 0:
        break

    _list = []

    for _ in range(cases):
        _list.append(input())

    _list = sorted(_list, key = lambda x:(x[0], x[1]))

    for item in _list:
        print(item)
