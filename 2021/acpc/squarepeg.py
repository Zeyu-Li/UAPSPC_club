import math

l, r = map(int, input().split())

if math.sqrt(2)*r >= l: print("fits")
else: print("nope")
