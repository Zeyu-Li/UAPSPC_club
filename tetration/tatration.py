""""
find inverse factorial by Andrew Li
Description: given number, find inverse factoral
"""
from math import floor

def main():

    x = float(input('Tetrate: '))
    for v in range(1000):
        x = tetration(x)

    print(x)


def tetration(x):
    return pow(x, x)


# system calls main
if __name__ == "__main__":
    main()