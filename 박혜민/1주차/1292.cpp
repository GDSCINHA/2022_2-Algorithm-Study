#include<iostream>
#include<array>

using namespace std;

int main() {
	//배열 선언
	array<int, 1000>arr{};
	//인덱스
	int t = 0;
	//배열 할당
	for (unsigned int i{ 1 }; i <= 45; i++) {
		int n = 0;
		while (n < i&&t<=999) {
			arr[t] = i;
			t++;
			n++;
		}
	}
	//합 구하기
	int a, b;
	cin >> a >> b;
	int total = 0;
	for (unsigned int i = a - 1; i <= b - 1; i++) {
		total += arr[i];
	}

	cout << total;

	
}