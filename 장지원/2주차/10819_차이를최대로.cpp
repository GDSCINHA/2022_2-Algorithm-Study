#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr, vector<bool> visited, int N) {

    int max = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (visited[i] != true) {
            visited[i] = true;
            int result = solution(arr, visited, arr[i]);
            int cur = abs(N - arr[i]);
            if (max < cur + result) {
                max = cur + result;
            }
            visited[i] = false;
        }
    }
    return max;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        visited[i] = true;
        int result = solution(arr, visited, arr[i]);
        if (result > max) {
            max = result;
        }
        visited[i] = false;
    }
    cout << max;
}
