#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//[BOJ] / 2252. 줄 세우기 / 골드 3 / 40분

//위상정렬 문제
//사실 위상정렬을 처음 해봐서 미리 블로그 글을 읽고 문제를 풀었습니다...
//https://m.blog.naver.com/ndb796/221236874984
//핵심은 indegree를 계속 업데이트 해주면서 0인 정점을 큐에 넣는 방식

int main() {
	int n, m; cin >> n >> m;
	vector<int>tmp;
	vector<int>inedge(n + 1, 0); //해당 노드에 들어오는 엣지가 몇개인지 카운팅
	vector<vector<int>>edge(n + 1, tmp);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		inedge[b]++;
	}

	vector<int>ret;

	queue<int>q;
	//처음에 indegree 0 인 정점 모두 큐에 삽입
	for (int i = 0; i < n; i++) {
		if (inedge[i + 1] == 0) {
			q.push(i + 1);
		}
	}
	//큐에 있는곳 하나하나 보면서 엣지를 지우고 indegree업데이트 후 0이면 큐에 삽입
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		ret.push_back(here);
		for (int i = 0; i < edge[here].size(); i++) {
			int now = edge[here][i];
			inedge[now]--;
			if (inedge[now] == 0) {
				q.push(now);
			}

		}
	}

	for (int i = 0; i < n; i++) {
		cout << ret[i] << " ";
	}
}