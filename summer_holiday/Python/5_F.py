n, k = (int(x) for x in input().strip().split(" "))
L = list(int(x) for x in input().strip().split(" "))
a_list = []
b_list = [0] * k
for i in range(n):
    b_list[L[i] % k] += 1


ans = 0
for i in range(k):
    j = (k - i) % k
    if j < i:
        break
    elif j == i:
        ans += b_list[i] * (b_list[i] - 1) // 2
    else:
        ans += b_list[i] * b_list[j]
print(ans)


