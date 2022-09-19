#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr(3);
    for(int i = 0; i < 3; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i < 3; i++){
        cout << arr[i] << " ";
    }
    
}
