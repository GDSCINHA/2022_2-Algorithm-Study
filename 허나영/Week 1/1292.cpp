#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int cnt = 0; int num = 1;
	while (cnt <= 1000) {
		for (int i = 0; i < num; i++) {
			v.push_back(num);
			cnt++;
		}
		num++;
	}
	int a, b; cin >> a >> b;
	int sum = 0;
	for (int i = a - 1; i < b; i++) sum += v[i];
	cout << sum;
}