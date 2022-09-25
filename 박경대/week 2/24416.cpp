#include<iostream>

using namespace std;

int fib(int n){
    if(n==1 || n==2) return 1;
    else return (fib(n-1)+fib(n-2));
}

int fibonacci(int n){
    int cnt = 0; // 실행횟수
    int f[41];
    f[1] = 1;
    f[2] = 1;
    for(int i=3;i<=n;i++){
        f[i] = f[i-1] + f[i-2];
        cnt++;
    }
    return cnt;
}


int main(){
    int n; cin>>n;
    cout<<fib(n)<<" ";
    cout<<fibonacci(n);
}