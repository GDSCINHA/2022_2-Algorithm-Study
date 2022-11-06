#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

//[BOJ] / 14888. 연산자 끼워넣기 / 실버 1 / 30분

int mmax = -1000000000, mmin = 1000000000, n;

void bfs(vector<int>num, vector<int>oper, int here, int res) {
	if (here >= n - 1) {
		mmax = max(mmax, res);
		mmin = min(mmin, res);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			int tmpres;
			if (i == 0) { //+
				tmpres = res + num[here + 1];
			}
			if (i == 1) { //-
				tmpres = res - num[here + 1];
			}
			if (i == 2) { //*
				tmpres = res * num[here + 1];
			}
			if (i == 3) { ///
				tmpres = res / num[here + 1];
			}			
			bfs(num, oper, here + 1, tmpres);
			oper[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> num;
	vector<int>oper(4, 0); //+-*/
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp; num.push_back(tmp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	//bfs 처럼
	bfs(num, oper, 0, num[0]);

	cout << mmax << "\n" << mmin;
}