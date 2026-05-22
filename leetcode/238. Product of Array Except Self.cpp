#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<vector>

int arr1[100001], arr2[100001];

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> nums;
	for(int i = 0;i < n; i++){
		int x;
		cin >> x;
		nums.push_back(x);
	}
	memset(arr1, 0, sizeof(arr1));
	memset(arr2, 0, sizeof(arr2));
	
	arr1[0] = nums[0];
	arr2[nums.size()-1] = nums[nums.size()-1];
	
	for(int i = 1; i < nums.size(); i++){
		arr1[i] = arr1[i-1] * nums[i];
	}
	
	for(int i = nums.size()-2; i >= 0; i--){
		arr2[i] = arr2[i+1] * nums[i];
	}
	
	for(int i = 0; i < nums.size(); i++){
		cout << arr1[i] << " ";
	}
	cout << endl;
	
	for(int i = 0; i < nums.size(); i++){
		cout << arr2[i] << " ";
	}
	cout << endl;
	
	vector<int> v;
	for(int i = 0;i < nums.size(); i++){
		if(i == 0) v.push_back(arr2[i+1]);
		else if(i == nums.size() - 1) v.push_back(arr1[i-1]);
		else{
			v.push_back(arr1[i-1] * arr2[i+1]);
		}
	}
	for(int i = 0;i < n; i++){
		cout << v[i];
	}
	
	return 0;
}