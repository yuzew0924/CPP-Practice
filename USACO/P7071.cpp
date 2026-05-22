#include <iostream>
#include <cmath>
using namespace std;

int n;
string x = "";
int main(int argc, char *argv[]) {
	cin >> n;
	while(n != 0){
		x = to_string(n%2) + x;
		n /= 2;
	}
	if(x[x.length()-1] == '1') cout << "-1";
	else{
		for(int i=0;i<x.length();i++){
			//cout << x[i] << " ";
			if(x[i] == '1'){
				cout << (long long)pow(2,x.length()-1-i) << " ";
			}
		}
	}
}