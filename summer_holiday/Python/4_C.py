n = int(input().strip())
a_stack = [i for i in range(1, n+1)]
L = list(int(x) for x in input().strip().split(" "))
i = 0
new_list = []
for A in a_stack:
    new_list.append(A)
    while len(new_list) and L[i] == new_list[-1]:
        new_list.pop()
        i += 1
if len(new_list):
    print("No")
else:
    print("Yes")

