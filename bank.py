foo = input()
number, time = foo.split

collection = []
for i in range(number):
    bar = input()
    bar = bar.split()

    x, y = int(bar[0]), int(bar[1])
    collection.append([x/y, x, y])

sorted(collection, key=lambda sl: (sl[0],sl[2]))

i = 0
while time >= 0:
    if (time - collection[i][2] >= 0):
        time -= collection[i][2]
    i+=1