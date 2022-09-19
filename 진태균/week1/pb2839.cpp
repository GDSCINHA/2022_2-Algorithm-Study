#include <iostream>
using namespace std; 

int main() {
	int n; //초기 입력값
	cin >> n;
	int q; //몫
	int r; //나머지
	int res; //결과값

	q = n / 5;  
	r = n % 5;
	if (r == 0) {
		res = q;
	}
	else {
		if (r == 3) {
			res = q + 1;
		}
		else { // r != 3
			while (r % 3 != 0) {
				
				q = q - 1;
				if (q < 0) {
					cout << -1 << endl;
					return 0;
				}
				r = r + 5;
			}
			res = q + (r / 3);
		}
	}
	cout << res << endl;
}