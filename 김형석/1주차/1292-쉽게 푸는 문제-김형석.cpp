// 1292번, 쉽게 푸는 문제
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	// sum_A: A번째 숫자까지의 합, sum_B: B번째 숫자까지의 합, num: 현재 숫자, cnt: 숫자가 나온 횟수
	int sum_A = 0, sum_B = 0, num = 1, cnt = 0;;
	// A번째 숫자까지의 합
	for (int i = 0; i < A - 1; i++) {
		if (cnt == num) {
			num++;
			cnt = 0;
		}
		sum_A += num;
		cnt++;
	}

	// B번째 숫자까지의 합
	num = 1, cnt = 0;
	for (int i = 0; i < B; i++) {
		if (cnt == num) {
			num++;
			cnt = 0;
		}
		sum_B += num;
		cnt++;
	}

	cout << sum_B - sum_A << '\n';

	return 0;
}