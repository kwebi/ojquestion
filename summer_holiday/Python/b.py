from itertools import permutations


def get_new_num(num):
    _min = int(''.join(sorted(num)))
    _max = int(''.join(sorted(num,reverse=True)))
    return str(_max-_min)


def get_circle(num):
    circle = [num]
    num_len = len(num)
    while True:
        num = get_new_num(num)
        _new_num_len = len(num)
        if _new_num_len != num_len:
            num = num + '0' * (num_len-_new_num_len)
        for i,circle_num in enumerate(circle):
            if num == circle_num:
                return ' '.join(circle[i:])
        else:
            circle.append(num)


nums = []
num = input()
try:
    while num.strip():
        nums.append(str(int(num)))
        num = input()

except EOFError:
    pass
for num in nums:
    print(get_circle(num))
