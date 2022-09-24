from itertools import permutations

n = int(input())
nums = [int(n) for n in input().split()]
case = list(permutations(nums, n))
ans = 0
can = 0

for i in case :
    can = 0
    for k in range(len(i)-1) :
        can += abs(i[k]-i[k+1])
    if can > ans :
        ans = can
print(ans)