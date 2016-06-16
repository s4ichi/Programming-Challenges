import sys
import math

t = 1
num = 1501*[0]
fib = 1501*[0]

fib[0] = fib[1] = num[1] = 1

for i in range(2, 1500):
    fib[i] = fib[i-1] + fib[i-2]
    num[i] = num[i-1] + fib[i-1]

while 1:
    n = int(input())

    if n == 0:
        break;

    print("Set {0}:".format(t))
    print(num[n-1] + (fib[n-1] - 1) // 2)

    t = t + 1
