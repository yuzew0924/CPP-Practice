#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;
int n;
vector<int> digits;
int main(int argc, char *argv[]) {
	cin >> n;
	for(int i = 0;i < n;i ++){
		int x;
		cin >> x;
		digits.push_back(x);
	}
	for(int i = digits.size()-1; i >= 0; i--){
		if(digits[i] != 9){
			digits[i] += 1;
			break;
		}
		digits[i] = 0;
		if(i == 0){
			digits.insert(digits.begin(), 1);
			break;
		}
	}
	for(int i = 0; i < digits.size(); i++) 	cout << digits[i] << " ";
		
	return 0;
}