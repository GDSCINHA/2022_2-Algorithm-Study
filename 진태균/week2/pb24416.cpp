#include <iostream>
using namespace std;

int recursionCount = 0;
int dynamicCount = 0;

int fib(int n) {
	if (n == 1 || n == 2) {
		recursionCount++;
		return 1;
	}
	else {
		return (fib(n - 1) + fib(n - 2));
	}
}

void fibonacci(int n) {
	int f[41];
	for (int i = 0; i < 41; i++) {
		f[i] = 0;
	}
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		dynamicCount++;
	}

}

int main() {
	int n;
	cin >> n;
	fib(n);
	fibonacci(n);
	cout << recursionCount << " " << dynamicCount << endl;
	return 0;
}