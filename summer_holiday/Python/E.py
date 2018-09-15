n = int(input().strip())
str = input().strip()
L = []
for i in range(n):
    ch = input()
    L.append(ch)
low_str = str.lower()
c_list = low_str.split(" ")
if c_list[-1][-1] == '!' and len(c_list) != 0:
    is_have = True
    c_list[-1] = c_list[-1][:-1]
else:
    is_have = False
num = 0
for i in c_list:
    for ch in L:
        if (len(ch) == len(i)):
            j = 0
            k = 0
            while (j < len(ch)):
                if ch[j] == i[j]:
                    j = j + 1
                    continue
                else:
                    k = k + 1
                    j = j + 1
            if (k == 1):
                num += 1
                ch_index = c_list.index(i)
                c_list[ch_index] = ch
new_str = " ".join(c_list)
new_str = new_str[0].upper() + new_str[1:]
print(num)
if is_have:
    print(new_str + '!')
else:
    print(new_str)
