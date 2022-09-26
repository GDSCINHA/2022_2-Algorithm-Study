#include <iostream>
using namespace std;

int arr[41];
int n{ 0 };
int count1{ 0 };
int count2{ 0 };


int fib(int a) {
	if (a == 1 || a == 2) {
		count1++;
		return 1;
	}
	else return (fib(a - 1) + fib(a - 2));
}

int main() {
	cin >> n;
	fib(n);

	arr[1] = arr[2] = 1;
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		count2++;

	}
	cout << count1 << " " << count2 << endl;
	return 0;
}