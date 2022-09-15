#include <iostream>
using namespace std;

int N;
int main() {
	cin >> N;
	int sum = 0;
	while (N >= 0) {
		if (N % 5 == 0) {
			sum += N / 5;
			cout << sum << '\n';
			return 0;
		}
		N -= 3; sum++;	
	}
	cout << -1 << '\n';
}
// greedy algorithm