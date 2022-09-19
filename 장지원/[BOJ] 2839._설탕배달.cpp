#include <iostream>
#include <vector>

using namespace std;

//DP
int main() {
    int N;
    cin >> N;
    vector<vector<int>> dp((N / 3) + 1, vector<int>((N / 5) + 1));
    int ans = (N / 3) + 2;
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            dp[i][j] = 3 * i + 5 * j;
            if (dp[i][j] == N) {
                if (ans > i + j) {
                    ans = i + j;
                }
            }
            if (dp[i][j] > N) {
                break;
            }
        }
    }
    if (ans != (N / 3) + 2) {
        cout << ans;
    }
    else {
        cout << -1;
    }
}

/***********************************************************************************************
Greedy
int calc(int &k3, int &k5, int N) {
	int _k5, _k3;
	_k5 = N / 5;
	while (true) {
		if ((N - (_k5*5)) % 3 == 0) {
			_k3 = (N - (_k5 * 5)) / 3;
			break;
		}
		else {
			_k5 -= 1;
			if (_k5 < 0) {
				return -1;
			}
		}
	}
	k3 = _k3;
	k5 = _k5;
	return 0;
	
}

int main() {
	int k3, k5;
	int N;
	cin >> N;

	if (calc(k3, k5, N) == -1) {
		cout << -1;
		return 0;
	}
	else {
		cout << k3 + k5;
		return 0;
	}
	
}
*/
