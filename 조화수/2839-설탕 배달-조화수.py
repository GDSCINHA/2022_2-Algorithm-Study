import sys

n = int(sys.stdin.readline())
bag = 0

while n >= 0 :
    if n % 5 == 0 :
        bag += n // 5
        print(bag)
        break
    else :
        n = n - 3
        bag += 1
else :
    print(-1)