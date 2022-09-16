// 2752번, 세수정렬
#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include <algorithm>
using std::swap;
using std::sort;

void BubbleSort(int[], int);
void InsertionSort(int[], int);
void SelectionSort(int[], int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num_arr[3];
	for (int i = 0; i < 3; i++)
		cin >> num_arr[i];

	//BubbleSort(num_arr, 3);
	InsertionSort(num_arr, 3);
	//SelectionSort(num_arr, 3);

	for (int i = 0; i < 3; i++)
		cout << num_arr[i] << ' ';
	cout << '\n';

	return 0;
}

// 버블정렬(=교환정렬)
void BubbleSort(int arr[], int size) {
	for(int i=0;i<size-1;i++)
		for (int j = i + 1; j < size; j++)
			if (arr[i] > arr[j])		// 오름차순
				swap(arr[i], arr[j]);
}

// 삽입정렬
void InsertionSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int key = arr[i];
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// 선택정렬
void SelectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int smallest = i;
		for (int j = i + 1; j < size; j++)
			if (arr[smallest] > arr[j])
				smallest = j;
		swap(arr[i], arr[smallest]);
	}
}