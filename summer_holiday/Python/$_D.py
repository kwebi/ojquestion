import re

new_str = input()
i = 0
if new_str[0] == '[' or new_str[0] == ']':
    new_str = new_str[1:]

while(i + 1 < len(new_str)):
    if new_str[i] == '[' and new_str[i+1] == ']':
        new_str = new_str[:i] + new_str[i+1:]
    elif new_str[i] == ']' and new_str[i+1] == '[':
        new_str = new_str[:i] + new_str[i+1:]
    i += 1
q = []
L = []
L = re.split(r"[\[\]]", new_str)
index1 = []
index2 = []
i = 1
k = 1

while(i < len(new_str)):
    if new_str[i] == '[':
        index1.append(k)
        k += 1
    elif new_str[i] == ']':
        index2.append(k)
        k += 1
    i += 1
q.append(L[0])
i = 0
while(i < len(L)):
    if i in index1:
        q.insert(0, L[i])
    elif i in index2:
        q.append(L[i])
    i += 1
print("".join(q))
