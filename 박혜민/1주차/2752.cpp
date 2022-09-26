#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	//배열 생성
	float a[3];
	//요소 입력
	for (float &item : a) {
		cin >> item;
	}
	//정렬
	sort(begin(a), end(a));
	//출력
	for (float& item : a) {
		cout << item << " ";
	}
}