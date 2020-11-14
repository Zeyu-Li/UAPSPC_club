string = input()
a = input()
b = input()
n = len(a)
m = len(b)

table = [[False for _ in range(m)] for i in range(n)]

table[n - 1][m - 1] = True

for i in range(n-1, -1, -1):
    for j in range(m-1, -1, -1):
        if (i + 1 < n):
            if (table[i + 1][j] and string[i + j] == a[i]):
                table[i][j] = True
        if (j + 1 < m):
            if (table[i][j + 1] and string[i + j] == b[j]):
                table[i][j] = True


print(table)
if (table[0][0]):
    print('yes')
else:
    print('no')