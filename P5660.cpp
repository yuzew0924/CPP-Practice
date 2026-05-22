#include <iostream>

using namespace std;

string x;
int cnt = 0;
int main(int argc, char *argv[]) {
	cin >> x;
	for(int i=0;i<x.length();i++){
		if(x[i]=='1') cnt++;
	}
	cout << cnt;
}