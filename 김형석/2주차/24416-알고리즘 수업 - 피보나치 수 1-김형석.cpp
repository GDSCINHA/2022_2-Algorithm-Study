// 24416번, 알고리즘 수업 - 피보나치 수 1
#include <cstdio>

#include <memory>
using std::unique_ptr;

int cnt_recursive, cnt_DP;

int fib(int);
int fibonacci(int);

int main() {
    int n;
    scanf("%d", &n);
    fib(n), fibonacci(n);

    printf("%d %d\n", cnt_recursive, cnt_DP);

    return 0;
}

int fib(int in_n) {
    if(in_n == 1 || in_n == 2) {
        cnt_recursive++;
        return 1;
    }
    else
        return fib(in_n - 1) + fib(in_n - 2);
}

int fibonacci(int in_n) {
    unique_ptr<int[]> F(new int[in_n]);

    F[0] = F[1] = 1;
    for(int i = 2; i < in_n; i++) {
        cnt_DP++;
        F[i] = F[i - 1] + F[i - 2];
    }

    return F[in_n - 1];
}