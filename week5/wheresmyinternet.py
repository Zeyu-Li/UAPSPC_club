
def take_first(elem):
    return elem[0]


def connect(connections, num, connected):
    for connection in connections:
        if connection[0] == num:
            connected.add(connection[1])
            connect(connections, connection[1], connected)
        elif connection[0] > num:
            break

def main():
    info = input()

    houses, cables = info.split(" ")

    cables = int(cables)
    houses = int(houses)

    connections = []

    for _ in range(cables):
        temp1, temp2 = input().split()

        temp1 = int(temp1)
        temp2 = int(temp2)

        # smallest number first
        if temp1 < temp2:
            connections.append((temp1, temp2))
        else:
            connections.append((temp2, temp1))

    connections.sort(key=take_first)

    connected = set([1])

    connect(connections, 1, connected)

    # debug
    # print(connections)
    if len(connected) == houses:
        print("Connected")
    else:
        # print non connected houses (1 is always connected)
        final = set(range(1, houses + 1)) - connected
        for i in final:
            print(i)



if __name__ == "__main__":
    main()
