// 1 22 333 4444 55555 666666
// 3 7이면 2 333 4 : 15
// 1 3이면 1 22 : 5
// 먼저 수열이 증가하는걸 구현하자
// 그리고 a,b가 해당하는 부분이 오면 그때 캐치

#include<iostream>
#define MAX 1000001
using namespace std;

int main(){
    int sum = 0;
    int inp1, inp2;
    cin>>inp1>>inp2;
    int count = 0; // 입력받은 a번째, b번째 수열임을 체크하기 위한 count변수
    // 수열을 만드는 이중 for문
    for(int i=1;i<=MAX;i++){ // 1,2,3,4,5를 위한 for문
        for(int j=1;j<=i;j++){ // 각 수열이 몇번 반복되는지, 가령 i가 5라면 j는 5번 돌아가며 5를 뽑아냄
            count++;
            if(inp1 <= count && count <= inp2) sum+=i; // 입력받은 두 수 사이의 값이면 sum에 누적
        } 
        if(count > inp2) break;
    }
    cout<<sum;
    return 0;
}