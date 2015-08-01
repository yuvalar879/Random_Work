__author__ = 'YUVAL'

import re, sys


def main():
    x = input()

    PassRegex = re.compile(r'^(?=.{8,})(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9]).*$')

    m = PassRegex.findall(x)

    if m != []:

        print(m)
    else:
        sys.exit()


main()
