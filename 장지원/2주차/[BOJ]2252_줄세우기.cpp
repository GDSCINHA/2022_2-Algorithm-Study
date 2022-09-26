/*************위상정렬*************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Node {
public:
    int in_degree;
    vector<int> child;
    Node() {
        this->in_degree = 0;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Node*> arr(N+1);
    for (int i = 0; i < N + 1; i++) {
        arr[i] = new Node();
    }
    for (int i = 0; i < M; i++) {
        int P, C;
        cin >> P >> C;
        arr[C]->in_degree += 1;
        arr[P]->child.push_back(C);
    }
    vector<int> ans;
    queue<int> Q;
    for (int i = 1; i <= N; i++) {
        if (arr[i]->in_degree == 0) {
            ans.push_back(i);
            Q.push(i);
        }
    }
    for (int i = 0; i < N; i++) {
        if (Q.empty()) {
            cout << "Cycle";
        }
        int cur = Q.front();
        Q.pop();
        for (int j = 0; j < arr[cur]->child.size(); j++) {
            if ((--arr[arr[cur]->child[j]]->in_degree) == 0) {
                Q.push(arr[cur]->child[j]);
                ans.push_back(arr[cur]->child[j]);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
