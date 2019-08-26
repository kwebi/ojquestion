n, k = (int(x) for x in input().strip().split(" "))
L = []
for i in range(n):
    L.append(float(input().strip()))
L = list(map(lambda x: x*100, L))
L = list(map(int, L))


def calc(x, n):
    sum_x = 0
    for j in range(n):
        sum_x += int(L[j]/x)
    return sum_x


sum_list = sum(L)
max_list = max(L)
res = 0
if sum_list * 100 < k:
    print('0.00')
else:
    left = 0
    right = 100 * max_list
    while right > left:
        mid = (right+left) / 2
        if calc(mid, n) >= k:
            res = max(res, mid)
            left += 1
        else:
            right -= 1

print("{:.2f}".format(res/100.0))


