#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int sum = 0;
    int Lsum = 0;
    int cur = 0;
    int idx = 0;
    while(idx < b){
        cur += 1;
        for(int i = 0; i < cur; i++){
            idx += 1;
            sum += cur;
            if(idx == a){
                Lsum = sum - cur;
            }
            if(idx == b){
                break;
            }
        }
    }
    cout << sum - Lsum;
    
}
