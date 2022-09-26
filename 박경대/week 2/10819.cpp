#include<iostream>
#include<vector>
#include<cstdlib>

#define MAX 8
using namespace std;

int n;
vector<int> v;
bool visited[MAX]={false};

int max_ = 0;
int total[MAX];
void func(int current){
    if(current == n){
        int sum  = 0;
        for(int i=0;i<n-1;i++){
            sum += abs(total[i] - total[i+1]);
        }
        if(max_ < sum) max_ = sum;
        return;
    }
    

    for(int i=0;i<n;i++){
        if(visited[i] == true) continue;
        total[current] = v[i];
        visited[i] = true;
        func(current+1);
        visited[i] = false;
    }


}
int main(){
    vector<int> total;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp; cin>>tmp;
        v.push_back(tmp);
    }
    func(0);
    cout<<max_;
    return 0;
}