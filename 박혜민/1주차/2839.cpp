#include<iostream>

using namespace std;

int c{ 0 };

//3의 배수 계산함수
void threex(int num) {
	if (num < 15) {
		while(num > 0){
			num -= 3;
				c++;
		}
	}
	else {
		while (true) {
			num -= 5;
			c++;
			if ((num <= 12) && (num % 3 == 0)) {
				while (num > 0) {
					num -= 3;
					c++;
				}
				break;
			}


		}
	}
	cout << c;
}

int main(){
	int n;
	cin >> n;
	//n이 3의 배수
	if (n % 3 == 0) {
		threex(n);
	}
	//n이 4
	else if (n == 4) {
		cout << -1;
	}
	//그 외
	else {
		while (n >= 5) {
			n -= 5;
			c++;
			//3의 배수일 때 함수계산
			if (n % 3 == 0) {
				threex(n);
				return 0;
			}
			//0 나오면 종료
			if (n == 0) {
				cout << c;
				return 0;
			}

		}
		//그 외 -1 출력
		cout << -1;

	}

}
