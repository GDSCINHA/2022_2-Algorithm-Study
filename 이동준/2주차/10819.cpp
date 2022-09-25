#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//[BOJ] / 10819. 차이를 최대로 / 실버 2 / 30분

int cal(vector<int>v) {
	int ret = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] - v[i + 1] < 0)
			ret += -(v[i] - v[i + 1]);
		else
			ret += (v[i] - v[i + 1]);
	}
	return ret;
}

int main() {
	int n; cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ret = 0;
	//next_permutaiton 쓰려면 정렬해야 한다고 하네요
	sort(v.begin(), v.end());
	do {
		ret = max(ret, cal(v));
	} while (next_permutation(v.begin(), v.end()));
	//순열 만드는거 가져다 쓰긴 했는데 직접 구현 해보는것도 좋을거 같아요. 좀 복잡하긴 하지만...
	//https://ansohxxn.github.io/algorithm/permutation/
	cout << ret;
}