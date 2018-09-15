n = int(input().strip())
L = []
while n // 2 > 1:
    L.append(n//2)
    L.append(n%2)
    L.append(n//2)
    n = n // 2
