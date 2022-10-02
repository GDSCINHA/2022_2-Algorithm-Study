#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// [BOJ] / 11048. 이동하기 / 실버 2 / 10분

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> miro;
	for (int i = 0; i < n; i++) {
		vector<int>tmp(m,0);
		for (int j = 0; j < m; j++) {
			cin >> tmp[j];
		}
		miro.push_back(tmp);
	}

	//dp인데 대각선 이동은 큰 의미 없음. 구현할 때 무시해도됨
    //현재 위치 = 본인 + (왼쪽이나 위중 큰 값)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int up = 0, left = 0;
			if (i != 0)
				up = miro[i - 1][j];
			if (j != 0)
				left = miro[i][j - 1];
			miro[i][j] += max(up, left);
		}
	}

	cout << miro[n - 1][m - 1];
}