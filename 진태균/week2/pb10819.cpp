#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	int n; // 정수 개수
	int elem; // 입력받을 정수
	int sum = 0; //총합
	cin >> n;
	vector<int> v; //정수를 저장할 벡터
	for (int i = 0; i < n; i++) { //정수 입력받고, 벡터에 저장
		cin >> elem;
		v.push_back(elem);
	}
	sort(v.begin(), v.end()); //벡터 정렬

	if (n % 2 == 0) {
		for (int i = 0; i < n / 2 - 1; i++) {
			sum = sum - 2 * v[i];
		}
		sum = sum - v[n / 2 - 1];
		sum = sum + v[n / 2];
		for (int i = n / 2 + 1; i < n; i++) {
			sum = sum + 2 * v[i];
		}
	}
	else {
		for (int i = 0; i < n / 2; i++) {
			sum = sum - 2 * v[i];
		}
		sum = sum + v[n / 2];
		sum = sum + v[n / 2 + 1];
		for (int i = n / 2 + 2; i < n; i++) {
			sum = sum + 2 * v[i];
		}
	}
	cout << sum << endl;
}