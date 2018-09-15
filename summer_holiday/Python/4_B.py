from collections import deque

n = int(input().strip())
q = deque()
i = 1
res = 0
while(i <= n):
    q.appendleft(i)
    i += 1
i = 1
while(i <= n and len(q) != 0):
    q_size = len(q)
    e_head1 = q.pop()
    if q_size != 1:
        e_head2 = q.pop()
    point = e_head1 % i
    res += point
    if q_size != 1:
        q.appendleft(e_head2)
    i += 1
print(res)
