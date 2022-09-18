#include <iostream>
using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c;

	if (a < b) {
		if (b < c) { //a < b < c
			cout << a << " " << b << " " << c << endl;
		}
		else { // (b > c)
			if (a < c) { //a < c < b
				cout << a << " " << c << " " << b << endl;
			}
			else { //c < a < b
				cout << c << " " << a << " " << b << endl;
			}
		}
	}
	else { // (a > b)
		if (b > c) { // c < b < a
			cout << c << " " << b << " " << a << endl;
		}
		else { // (b < c)
			if (a < c) {
				cout << b << " " << a << " " << c << endl;
			}
			else {
				cout << b << " " << c << " " << a << endl;
			}
		}
	}
}