// 2839번, 설탕 배달
#include <iostream>
using namespace std;

int main() {
    // N: N킬로그램 설탕, count_5: 5킬로그램 봉지수, count_3: 3킬로그램 봉지수
	int N, count_5 = 0, count_3 = 0;
	cin >> N;

    // 최대한 5킬로그램 봉지로 담아보고 안되면 5킬로그램 봉지를 1개씩 빼면서 3킬로그램 봉지로 정확하게 N킬로그램을 만들 수 있는지 확인
	count_5 = N / 5;
	for (int i = 0; i <= (N / 5); i++) {
		int temp = N - count_5 * 5;
		if (temp % 3 == 0) {
			count_3 = temp / 3;
			break;
		}
		else
			count_5--;
	}

	cout << count_3 + count_5 << endl;

	return 0;
}