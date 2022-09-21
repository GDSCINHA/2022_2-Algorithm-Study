#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> topol[32001];
bool visited[32001];

void DFS(int x) {
    visited[x] = true;
    for (int i = 0; i < topol[x].size(); i++) {
        if (!visited[topol[x][i]]) DFS(topol[x][i]);
    }
    cout << x << ' ';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        topol[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) DFS(i);
    }
    cout << '\n';
}