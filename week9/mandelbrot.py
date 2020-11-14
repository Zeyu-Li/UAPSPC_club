import sys

lines = sys.stdin.readlines()

i = 1
for line in lines:
    line = list(map(float, line.strip().split()))
    x = line[0]
    y = line[1]
    r = int(line[2])

    count = 1
    while count < r and x*x+y*y < 4:
        tmp = x
        x = x*x-y*y+line[0]
        y=2*tmp*y+line[1]
        count+=1

    if x*x +y*y >= 4:
        print(f"CASE {i}: OUT")
    else:
        print(f"CASE {i}: IN")

    i+=1