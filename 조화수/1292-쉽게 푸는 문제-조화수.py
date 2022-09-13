a, b = map(int, input().split())
cnt = 0
num = 1
ans = 0

for i in range(b) :
    ans += num
    cnt += 1
    if cnt == num :
        num += 1
        cnt = 0
cnt = 0
num = 1
for k in range(a-1) :
    ans -= num
    cnt += 1
    if cnt == num :
        num += 1
        cnt = 0

print(ans)