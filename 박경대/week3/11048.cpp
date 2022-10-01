#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1001
using namespace std;

int N,M;
int map[MAX][MAX]={};
int dp[MAX][MAX]={};

int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>map[i][j];
        }
    }
    int result = 0;
    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            result = max(max(dp[y-1][x],dp[y][x-1]),dp[y-1][x-1]);
            dp[y][x] = map[y][x] + result;
        }
    }
    cout<<dp[N][M];
}