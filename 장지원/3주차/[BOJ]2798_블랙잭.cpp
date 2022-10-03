#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int sum = 0;
    for (int i = 0; i <= N - 3; i++) {
        int left = i + 1, right = N - 1;
        while (left < right) {
            int temp = arr[i] + arr[left] + arr[right];
            if (temp < M) {
                if (sum < temp) {
                    sum = temp;
                    left += 1;
                }
                else {
                    left += 1;
                }
            }
            else if (temp > M) {
                right -= 1;
            }
            else {
                sum = temp;
                break;
            }
        }
        if (sum == M) {
            break;
        }
    }
    cout << sum;
}
