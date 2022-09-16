#include<iostream>
using namespace std;

int main(){
    int arr[3] = {};
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }
    int max = 0;
    int min = 1000001;
    int mid;
    for(int i=0;i<3;i++){
        if(arr[i] > max) max=arr[i];
        if(arr[i] < min) min=arr[i];
    }
    for(int i=0;i<3;i++){
        if(arr[i]!=max && arr[i]!=min)
        mid = arr[i];
    }
    cout<<min<<" "<<mid<<" "<<max;
}