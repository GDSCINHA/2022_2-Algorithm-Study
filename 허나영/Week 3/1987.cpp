#include <iostream>
#include <algorithm>
using namespace std;

int R, C, result;
char board[21][21];
bool alpha[26];

int ax[4] = { -1,1,0,0 };
int ay[4] = { 0,0,-1,1 };

void dfs(int x, int y, int ans) {
	result = max(ans, result);

	for (int i = 0; i < 4; i++) {
		int bx = x + ax[i];
		int by = y + ay[i];

		if (bx < 0 || bx >= R || by < 0 || by >= C) continue;
		int num = (int)board[bx][by] - 65;
		if (!alpha[num]) continue;

		alpha[num] = false;
		dfs(bx, by, ans + 1);
		alpha[num] = true;
	}
}
int main() {
	cin >> R >> C;
	for (int i = 0; i < 26; i++) { alpha[i] = true; }
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	int first = (int)board[0][0] - 65;
	alpha[first] = false;
	dfs(0, 0, 1);

	cout << result;
	
}