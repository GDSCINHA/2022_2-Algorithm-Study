#include <iostream>
using namespace std;

int main() {
		int Nk;
		cin >> Nk;
		if (Nk >= 3 && Nk <= 5000) {
			int bong = Nk / 5;
			int na = Nk % 5;
			bong += na / 3;
			if(na%3 == 0)
			cout << bong;
			else {
				cout << -1;
			}
		}
		else {
			cout << "3이상 5000이하의 무게를 입력하세요";
		}


}