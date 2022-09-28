#include <iostream>
#include <algorithm>
using namespace std;

int board[1001][1001];
int dp[1001][1001];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	dp[1][1] = board[1][1];
	int tmp1, tmp2, tmp3;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;
			tmp1 = board[i][j] + dp[i][j - 1];
			tmp2 = board[i][j] + dp[i - 1][j];
			tmp3 = board[i][j] + dp[i - 1][j - 1];

			dp[i][j] = max(tmp1, max(tmp2, tmp3));
		}
	}
	cout << dp[n][m];
}