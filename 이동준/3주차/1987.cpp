#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// [BOJ] / 1987. 알파벳 / 골드 4 / 1시간 이상 답지 참고

//dfs?
int ret = 0, r, c;
char board[20][20];

void dfs(int x, int y, bool dup[26], int len) {
	int dirx[4] = { 0,1,0,-1 }; int diry[4] = { 1,0,-1,0 };
	ret = max(ret, len);
	for (int i = 0; i < 4; i++) {
		int nextx = x + dirx[i], nexty = y + diry[i];
		if (nextx >= 0 && nextx < r && nexty >= 0 && nexty < c) {
			if (!dup[board[nextx][nexty]-'A']) {
				//근데 또 생각해 보니깐 알파벳을 이렇게 하면 O(N)이니까 visited 처럼 O(1)에 알수있게 할수 있을듯
                //근데 또 생각해보니까 r*c visited는 필요 없음
				//dup.push_back(board[nextx][nexty]);
				dup[board[nextx][nexty] - 'A'] = true;
                //여기서 확인하니까 99퍼에서 틀림
				/*ret = max(ret, len + 1);*/
				dfs(nextx, nexty, dup, len + 1);
				dup[board[nextx][nexty] - 'A'] = false;
			}
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}
	bool dup[26] = { false };
	dup[board[0][0] - 'A'] = true;
	dfs(0, 0, dup, 1);
	cout << ret;
}

//삽질 흔적
//vector 보다는 그냥 배열을 쓰는게 더 빠른가봄 아무때나 백터 쓰지 말자...
//새로 할당하고 복사하면 시간 오지게 오래걸림 이렁게 하지 말자...
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//// [BOJ] / 1987. 알파벳 / 골드 4 / 5+40~25
//
////dfs?
//int ret = 0, r, c;
//vector<vector<char>>board;
//
//void dfs(int x, int y, vector<bool> dup, vector<vector<bool>>visited, int len) {
//	int dirx[4] = { 0,1,0,-1 }; int diry[4] = { 1,0,-1,0 };
//	for (int i = 0; i < 4; i++) {
//		int nextx = x + dirx[i], nexty = y + diry[i];
//		if (nextx >= 0 && nextx < r && nexty >= 0 && nexty < c) {
//			if (!visited[nextx][nexty] && find(dup.begin(), dup.end(), board[nextx][nexty]) == dup.end()) {
//				/*vector<char>tmpdup = dup;
//				tmpdup.push_back(board[nextx][nexty]);
//				vector<vector<bool>>tmpvisited = visited;
//				tmpvisited[nextx][nexty] = true;
//				ret = max(ret, (int)tmpdup.size());
//				dfs(nextx, nexty, tmpdup, tmpvisited);*/
//
//				//근데 또 생각해 보니깐 알파벳을 이렇게 하면 O(N)이니까 visited 처럼 O(1)에 알수있게 할수 있을듯
//				//dup.push_back(board[nextx][nexty]);
//				dup[board[nextx][nexty] - 'A'] = true;
//				visited[nextx][nexty] = true;
//				ret = max(ret, len + 1);
//				dfs(nextx, nexty, dup, visited, len + 1);
//				visited[nextx][nexty] = false;
//				dup[board[nextx][nexty] - 'A'] = false;
//				//dup.pop_back();
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> r >> c;
//	for (int i = 0; i < r; i++) {
//		vector<char>tmp(c, ' ');
//		for (int j = 0; j < c; j++) {
//			cin >> tmp[j];
//		}
//		board.push_back(tmp);
//	}
//	vector<vector<bool>>visited;
//	visited.assign(r, vector<bool>(c, false));
//	visited[0][0] = true;
//	vector<bool>dup(26, false);
//	dup[board[0][0] - 'A'] = true;
//	dfs(0, 0, dup, visited, 1);
//	cout << ret;
//}