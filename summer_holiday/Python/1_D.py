a, b = (int(x) for x in input().strip().split(" "))
res = abs(a - b)
str_res = str(res)
length = len(str_res)
list_res = [ch for ch in str_res]
new_list = []
i = length
while(i-3 >= 0):
    new_list.insert(0, "".join(list_res[i-3:i]))
    i -= 3
if i != 0:
    new_list.insert(0, "".join(list_res[0:i]))
new_str = ",".join(new_list)
if a - b < 0:
    print("-", end="")
    print(new_str)
else:
    print(new_str)