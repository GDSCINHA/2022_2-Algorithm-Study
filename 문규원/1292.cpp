#include <iostream>

using namespace std;

int main() {
    int num[1000]{};
    int a = 0;
    int b = 0;
    int c = 0;
    cin >> a >> b;

    for (int i{ 1 }; i <= 45; i++) {
        for (int j{ 1 }; j <= i; j++) {
            num[c] = i;
            c++;
            if (c > 999) {
                break;
            }
        }
        
    }
    int sum = 0;

    for (int k = a - 1; k <= b - 1; k++) {
        sum += num[k];
    }
    cout << sum;
}
