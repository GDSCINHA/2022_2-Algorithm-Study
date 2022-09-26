// 10819번, 차이를 최대로
#include <iostream>
using std::ios_base;
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;

#include <cstdlib>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N);

	int min = 100, max = -100, diff_sum = 0;;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < min) min = A[i];		// 최솟값 찾기
		if (A[i] > max) max = A[i];		// 최댓값 찾기
	}

	diff_sum += (max - min);		// 최댓값과 최솟값의 차이를 가장 처음에 포함
	A.erase(find(A.begin(), A.end(), min));		// 최솟값을 배열 A에서 제거
	A.erase(find(A.begin(), A.end(), max));		// 최댓값을 배열 A에서 제거

	int index = 0;
	while (A.size() != 0) {		// 배열 A가 비었을 때까지 반복
		int index = 0, diff_max = -1;
		bool is_min = false;
		for (int i = 0; i < A.size(); i++) {		// 배열 A를 돌면서 최댓값과 최솟값 중에 차이가 가장 큰 경우를 찾음
			int temp = (abs(min - A[i]) > abs(max - A[i]) ? abs(min - A[i]) : abs(max - A[i]));
			if (diff_max < temp) {
				diff_max = temp;
				index = i;
			}
		}
		if (diff_max == abs(min - A[index]))		// 최솟값과의 차이가 가장 큰 경우
			is_min = true;
		diff_sum += diff_max;
		if (is_min) min = A[index];		// 최댓값과 최솟값 수정
		else max = A[index];
		A.erase(A.begin() + index);		// 배열 A에서 해당하는 숫자를 삭제
	}

	cout << diff_sum;

	return 0;
}