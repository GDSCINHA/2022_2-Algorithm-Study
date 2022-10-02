#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// [BOJ] / 2798. 블랙잭 / 브론즈 2 / 20분

int main() {
	int n, m; cin >> n >> m;
	int ret = 0;
	vector<int>card(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

    //사실 이부분 필요 없긴 함. 
    //처음에 정렬된 상태에서 가장 큰 수 3개씩 더해가다가 break 할라 했는데 문제 예시2번 해보면 안됨. 
    //그냥 모든 경우 다해봐야함
	sort(card.begin(), card.end());

	//3개만 1 나머지는 0인 조합용 백터
	vector<int>idx(n, 0);
	for (int i = 0; i < 3; i++) {
		idx[n - i - 1] = 1;
	}

	do {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (idx[i] == 1) 
				sum += card[i];
		}
		if (sum <= m) {
			ret = max(ret, sum);
		}

	} while (next_permutation(idx.begin(), idx.end()));

	cout << ret;
}