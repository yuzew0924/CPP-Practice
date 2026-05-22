#include <iostream>
#define ll long long
using namespace std;
int arr[20001];
int main(int argc, char *argv[]) {
	int n;
	ll b;
	cin>>n>>b;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+n, greater<int>());
	
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		sum += arr[i];
		if(sum > b){
			cout << i;
			return 0;
		}
	}
	return 0;
}