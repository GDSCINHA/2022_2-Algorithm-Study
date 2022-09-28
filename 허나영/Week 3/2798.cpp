#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101]{}; int ans[101];
int n, m;
vector<int> sum;
void combination(int k, int index, int n, int r) {
	if (k > n) return;
	if (index == r) {
		int s = 0;
		for (int i = 0; i < r; i++) { 
			s += ans[arr[i] - 1];
		}
		if (s <= m) sum.push_back(s);
	}
	else {
		arr[index] = k + 1;
		combination(k + 1, index + 1, n, r);
		combination(k + 1, index, n, r);
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ans[i];
	}
	combination(0, 0, n, 3);
	sort(sum.begin(), sum.end());
	cout << *sum.rbegin();
}