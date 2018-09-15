def get_circle(num):
    L = []
    num = str(int(num))
    length = len(num)
    t = "".join(sorted(num, reverse=True))
    L.append(t.zfill(length))
    if (num.zfill(length) not in L):
        L.append(num.zfill(length))
    while(len(set(L)) == len(L)):
        tmp = int("".join(sorted(L[-1], reverse=True))) - int("".join(sorted(L[-1])))
        L.append(str(tmp).zfill(length))
    tmp = int("".join(sorted(L[-1], reverse=True))) - int("".join(sorted(L[-1])))
    if (str(tmp).zfill(length) == L[-1]):
        print("{}".format(tmp))
    else:
        for ele in L:
            if (L.count(t.zfill(length)) == 2):
                ele_index = L.index(t.zfill(length))
                break
            elif (L.count(ele) == 2):
                ele_index = L.index(ele)
                break
        i = ele_index + 1
        print("{}".format(int(L[ele_index])), end=" ")
        L1 = []
        while (L[i] != L[ele_index] and i < len(L)):
            L1.append(str(int(L[i])))
            i = i + 1
        print(" ".join(L1))


num = input()

try:
    while num.strip():
        get_circle(num)
        num = input()
except EOFError:
    pass
