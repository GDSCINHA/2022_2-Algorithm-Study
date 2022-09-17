#include <iostream>
using namespace std;

int main(){
	int N, count=0, rest=0;
	int c5;
	bool flag=1;
	
	cin >> N;
	c5=N/5;
	
	do{
		count = c5 + (N-5*c5)/3;
		rest = (N-5*c5)%3;
		c5--;
	} while(!(rest==0) && !(c5 == -1));
	
	
	//결과값 출력 
	if(rest == 0)
		cout << count;
	else
		cout << -1;
}