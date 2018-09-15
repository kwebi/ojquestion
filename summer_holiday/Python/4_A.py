n, m = (int(x) for x in input().strip().split(" "))
L = []
for i in range(n):
    L.append([int(x) for x in input().strip().split(" ")])
new_list = []


for i in range(len(L[0])):
    new_bu_list = []
    for e in L:
        new_bu_list.insert(0, e[i])
    new_list.append(new_bu_list)
for i in range(len(new_list)):
    p_list = []
    for j in range(len(new_list[0])):
        p_list.append(str(new_list[i][j]))
    print(" ".join(p_list))
