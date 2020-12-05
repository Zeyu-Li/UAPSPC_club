import sys
sys.setrecursionlimit(1000000)

h, n, m = map(int, input().split())
grid = []
for _ in range(n):
    letters = input().split()
    new = []
    for letter in letters:
        if letter == '.':
            new .append(0)
        elif letter == '#':
            new.append(1)
        
    grid.append(new)
# print(grid)

def fill(i, j):
    if i < 0 or j < 0 or i >= n or j >= m:
        return 0
    if grid[i][j] == 1:
        return 0

    count = 1
    grid[i][j] = 1

    if i % 2 == 1:
        s = 0
        b = 2
    else:
        s = -1
        b = 1

    # top bottom
    for x in range(s, b):
        for y in [-1,1]:
            count += fill(i + y, j + x)

    # left right
    for x in [-1,1]:
        count += fill(i, j + x)

    return count

counts = []
for i in range(n):
    for j in range(m):
        tmp = fill(i, j)
        if tmp != 0:
            counts.append(tmp)

counts.sort()
# print(counts)
num = 0

while h > 0:
	h -= counts.pop()
	num += 1

print(num)
