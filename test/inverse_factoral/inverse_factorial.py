""""
find inverse factorial by Andrew Li
Description: given number, find inverse factoral
"""
from math import log, ceiling


def main():

    x = int(input('Inverse Factoral: '))
    while True:
        foo = log(x, 10)
        

# system calls main
if __name__ == "__main__":
    main()