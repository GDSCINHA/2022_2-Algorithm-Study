#include <iostream>
using namespace std;

int n1, n2;

int fib(int n) {
	if (n == 1 || n == 2) {
		n1++;
		return 1; // code 1
	}
	else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
	int f[41]{};
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++) {
		n2++;
		f[i] = f[i - 1] + f[i - 2]; // code 2
	}
	return f[n];
}

int main() {
	int n; cin >> n;
	
	fib(n);
	fibonacci(n);
	
	cout << n1 << ' ' << n2;
}