#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> arr(N,vector<int>(M));
    vector<vector<int>> dp(N,vector<int>(M,0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i == 0 && j == 0){
                dp[i][j] = arr[i][j];
            }
            else if (j ==0){
                dp[i][j] = dp[i-1][j]+arr[i][j];
            }
            else if (i == 0){
                dp[i][j] = dp[i][j-1]+arr[i][j];
            }
            else{
                dp[i][j] = max(max(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]) + arr[i][j];
            }
        }
    }
    cout << dp[N-1][M-1];
}
