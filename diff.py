from sys import stdin
for i in stdin:
    try:
        one, two = i.split()
    except:
        break
    one, two = int(one), int(two)
    print(abs(one-two))
