#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int dfs(int r, int c, int R, int C, bool visit[26], char arr[20][20]) {
    int sum = 0;
    if (visit[arr[r][c] - 'A'] == true) {
        return sum;
    }
    else {
        visit[arr[r][c] - 'A'] = true;
    }
    for (int i = 0; i < 4; i++) {
        int nx = c + dx[i];
        int ny = r + dy[i];
        if (nx < 0 || nx >= C || ny < 0 || ny >= R) {
            continue;
        }
        else {
            int temp = dfs(ny, nx, R, C, visit, arr);
            if (temp > sum) {
                sum = temp;
            }
        }
    }
    visit[arr[r][c] - 'A'] = false;
    return sum + 1;

}

int main() {
    int R, C;
    cin >> R >> C;
    char arr[20][20];
    bool visit[26] = { false, };
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    cout << dfs(0, 0, R, C, visit, arr);
}
