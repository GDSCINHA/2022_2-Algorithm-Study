#include <iostream>
#include <vector>

using namespace std;

int recur_fib(int n, long long* count) {
    
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        *count += 1;
        return recur_fib(n - 1, count) + recur_fib(n - 2, count);
    }
}

int dp_fib(int n, long long* count) {
    int dp[41];
    dp[1] = 1;
    dp[2] = 1;
    dp[0] = 1;
    for (int i = 3; i <= n; i++) {
        *count += 1;
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int N;
    cin >> N;
    long long recur_count = 0, dp_count = 0;
    recur_fib(N, &recur_count);
    dp_fib(N, &dp_count);
    cout << recur_count+1 << " " << dp_count;
}
