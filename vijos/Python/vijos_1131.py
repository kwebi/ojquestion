import math

x, y = (int(x) for x in input().strip().split(" "))

i = x * y

def is_max_min(P, Q):
    m = P
    n = Q
    while m != n:
        if m > n:
            m = m - n
        elif n > m:
            n = n -m
    x0 = m
    y0 = P * Q / x0
    return x0, y0


count = 0
n = False

sqrt_xy = int(math.sqrt(x*y))
while i >= sqrt_xy:
    j = sqrt_xy
    while j > 0:
        if i * j == x * y:
            x0, y0 = is_max_min(i, j)
            if x0 == x and y0 == y:
                if i == sqrt_xy and j == sqrt_xy:
                   n = True
                count += 1
        j -= 1
    i -= 1


if n:
    print(count * 2 -1)
else:
    print(count * 2)

