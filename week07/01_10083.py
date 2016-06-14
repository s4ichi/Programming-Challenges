import sys
import math

for line in sys.stdin:
    c = line.split()

    t = int(c[0])
    a = int(c[1])
    b = int(c[2])

    print(("({0}^{1}-1)/({0}^{2}-1) ".format(t, a, b)), end='')

    if t == 1 or a%b != 0 or (a-b)*math.log10(t) > 99.0:
        print('is not an integer with less than 100 digits.')
    elif a == b:
        print('1')
    else:
        ans = int( (t**a - 1) // (t**b - 1) )

        if len(str(ans)) >= 100:
            print('is not an integer with less than 100 digits.')
        else:
            print(ans)
