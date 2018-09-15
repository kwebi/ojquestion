import math
x = int(input().strip())
a = math.log(x)/math.log(3)
b = math.log(x)/math.log(5)
c = math.log(x)/math.log(7)
count = 0

for i in range(int(a)+1):
    for j in range(int(b)+1):
        for k in range(int(c)+1):
            res = pow(3,i)*pow(5,j)*pow(7,k)
            if (res != 1 and res <= x):
                count += 1
print(count)
