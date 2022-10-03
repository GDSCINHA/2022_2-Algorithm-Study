#include <vector>
using namespace std;

#include <cstdio>

int blackjack(const vector<int>&, int);

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> list(N);
	int input;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		list[i] = input;
	}

	printf("%d\n", blackjack(list, M));

	return 0;
}

int combination_count(int n, int r) {
	if ((r == 0) || (n - r == 0))
		return 1;
	else if ((r == 1) || (n - r == 1))
		return n;
	else
		return combination_count(n - 1, r - 1) + combination_count(n - 1, r);
}

int blackjack(const vector<int>& num_list, int in_M) {
	int sum_listSize = combination_count(int(num_list.size()), 3);
	int* sum_list = new int[sum_listSize]();

	int index = 0;
	for (unsigned i = 0; i < num_list.size() - 2; i++)
		for (unsigned j = i + 1; j < num_list.size() - 1; j++)
			for (unsigned k = j + 1; k < num_list.size(); k++)
				sum_list[index++] = num_list[i] + num_list[j] + num_list[k];

	int max_sum = 0, i;
	for (i = 0; i < sum_listSize; i++)
		if ((sum_list[i] <= in_M)) {
			max_sum = sum_list[i];
			break;
		}
	for (int j = i + 1; j < sum_listSize; j++)
		if ((sum_list[j] <= in_M) && (sum_list[j] > max_sum))
			max_sum = sum_list[j];

	delete[] sum_list;
	return max_sum;
}