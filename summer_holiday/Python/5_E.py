n, m = (int(x) for x in input().strip().split(" "))
L = list(int(x) for x in input().strip().split())
L.insert(0, 0)

for i in range(1, n):
    L[i] += L[i-1]


def check(length):
    my_sum = 0
    last = 0
    for i in range(1, n-1):
        if L[i]-L[last]>=length and L[n-1]-L[i]>=length:
            last = i
        else:
            my_sum += 1

    if my_sum <= m:
        return True
    else:
        return False


left = 1
right = L[n-1] - L[0]

while right > left+3:
    mid = (left+right) // 2
    if check(mid):
        left = mid
    else:
        right = mid

i = right
while i >= left:
    if check(i):
        print(i)
        break
    i -= 1
