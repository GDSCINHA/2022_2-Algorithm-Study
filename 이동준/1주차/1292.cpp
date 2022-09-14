#include <iostream>
using namespace std;

//[BOJ] / 1292. 쉽게 푸는 문제 / 브론즈 1 / 10분

int main() {
	int a, b; cin >> a >> b;
    //ret은 출력값, here는 현재 숫자, counter는 몇번째인지 카운터
	int ret = 0, here = 1, counter = 0;
	//b가 최대 1000까지라 대충 100으로 정함
    for (int i = 1; i < 100; i++) {
		for (int j = 0; j < i; j++) {
			counter++;
			if (counter >= a && counter <= b) {
				ret += here;
			}
		}
		here++;
	}
	cout << ret;
}