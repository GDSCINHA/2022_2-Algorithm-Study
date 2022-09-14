#include <iostream>
using namespace std;

//[BOJ] / 2839. 설탕 배달 / 실버 4 / 15분

int main() {
	int n; cin >> n;
	//그리디 5개짜리로 많이 채워야 전체 갯수가 작아짐
	//5000밖에 안되서 그냥 일일히 했는데 dp로도 할수 있을듯
	for (int i = n / 5; i >= 0; i--) {
		if ((n - i * 5) % 3 == 0) {
			cout << i + (n - i * 5) / 3;
			return 0;
		}
	}
	cout << -1;
}