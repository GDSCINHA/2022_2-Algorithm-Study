n = int(input())

def fibonacci(n) :
    lst = [0] * n
    lst[0], lst[1] = 1, 1
    cnt = 0
    for i in range(2, n) :
        cnt += 1
        lst[i] = lst[i-1] + lst[i-2]
    return lst[-1], cnt

print(*fibonacci(n))