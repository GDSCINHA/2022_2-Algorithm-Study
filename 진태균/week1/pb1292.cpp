#include <iostream>
using namespace std;

int main() {
	int arr[1001];
	for (int i = 0; i < 1001; i++) {
		arr[i] = 0;
	}

	int cur = 1;
	for (int i = 1; i <= 1001; i++) {
		if (cur > 1000) {
			break;
		}

		for (int j = 1; j <= i; j++) {
			arr[cur] = i;
			if (cur >= 1000) {
				break;
			}
			cur++;
		}
	}

	int a, b;
	cin >> a >> b;
	int sum = 0;
	for (int i = a; i <= b; i++) {
		sum = sum + arr[i];
	}
	cout << sum << endl;
}