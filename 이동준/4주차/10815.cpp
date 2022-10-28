#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

// [BOJ] / 10815. 숫자 카드 / 실버 5 / 20분

// 질문 참고
// https://www.acmicpc.net/board/view/99819

// 정렬+이진탐색 5224kb	208	ms 
// 그냥 set (균형 이진탐색 트리)25256kb	476ms
// 그냥 unordered_set (hash) 23040kb	384ms

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n;
	vector<int>s;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		s.push_back(tmp);
	}
	cin >> m;

	sort(s.begin(), s.end());

	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		int l = 0, r = n - 1 , mid = (l + r) / 2;
		while (l <= r) {
			if (s[mid] > tmp) {
				r = mid - 1; 
			}
			else {
				l = mid + 1;
			}
			mid = (l + r) / 2;
		}
		if (s[mid] == tmp)
			cout << "1 ";
		else
			cout << "0 ";
	}

	/*int n, m; cin >> n;
	unordered_set<int>s;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		s.insert(tmp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		if (s.find(tmp) != s.end())
			cout << "1 ";
		else
			cout << "0 ";
	}*/
}