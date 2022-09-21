#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[8];
int tmp[8];
bool visited[8];
int ans;
void solve() {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += abs(arr[i] - arr[i + 1]);
	}
	ans = max(ans, sum);
}
void backtracking(int x) {
	if (x == n) { solve(); return; }
	else {
		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			arr[x] = tmp[i];
			backtracking(x + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> tmp[i];
	backtracking(0);
	cout << ans;
}