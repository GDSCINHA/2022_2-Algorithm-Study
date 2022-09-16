#include<iostream>

#define MAX 5001
using namespace std;

int dp[MAX];
int main(){
    int N; cin>>N;
    for(int i=0;i<MAX;i++){
        dp[i] = -1;
    }
    dp[3] = 1;
    dp[5] = 1;

    if(N==3 || N == 5){
        cout<<1;
        return 0;
    }    
    if(N==4){
        cout<<-1;
        return 0;
    }

    for(int i=6;i<=N;i++){
        if(dp[i-5]!=-1){
            dp[i]=dp[i-5]+1;
        } else if(dp[i-3]!=-1){
            dp[i]=dp[i-3]+1;
        }
    }
    cout<<dp[N];
}