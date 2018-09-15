n, v = (int(x) for x in input().strip().split())

L = list(int(x) for x in input().strip().split())
count = [0]
x = [0]
i = 0
p = []

def combine(sum, x):
    if len(p) == n+1:
        return
    elif len(p) == 1:
        x[0] += 1
    i = x[0]
    while i < n:
        if (L[i] in p):
            i += 1
            continue
        else:
            if sum+L[i] <= v:
                count[0] += 1
                p.append(L[i])
                combine(sum+L[i], x)
                p.pop()
        i += 1
    if i >= n:
        return



combine(0,count)
print(count[0]+1)
