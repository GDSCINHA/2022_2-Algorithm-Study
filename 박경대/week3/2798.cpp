#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N,M;
vector<int> v;
void Solution(){
	int sum = 0;
	int result = 0;
	for(int i=0;i<N-2;i++){
		for(int j=i+1;j<N-1;j++){
			for(int k=j+1;k<N;k++){
				if(v[i]+v[j]+v[k]<=M){
					sum = v[i]+v[j]+v[k];
					if(sum>result) result = sum;
					}
				}
			}
		}
	
	cout<<result;
}
int main(){
	cin>>N>>M;
	for(int i = 0 ; i < N; i++){
		int input; cin>>input;
		v.push_back(input);
	}
	Solution();
}
