#include <iostream>
using namespace std;

//[BOJ] / 24416. 알고리즘 수업 - 피보나치 수 1 / 브론즈 1 / 5분

int recurCount = 0, dpCount = 0;

int recur(int n) {
	if (n == 1 | n == 2) {
		recurCount++;
		return 1;
	}		
	else
		return recur(n - 1) + recur(n - 2);
}

int main() {
	int n; cin >> n;
	recur(n); dpCount = n - 2;
	cout << recurCount << " " << dpCount;
}