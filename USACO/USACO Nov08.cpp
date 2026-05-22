#include <iostream>

using namespace std;
int n, m;
int arr[100001];

int main(int argc, char *argv[]) {
	cin >> m >> n;
	for(int i = 1; i <= n;i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+n);
	long long sum = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if((long long)arr[i] *(n-i+1) > sum){
			sum = (long long)arr[i] *(n-i+1);
			cnt = arr[i];
		}
	}
	cout << cnt << " "<<sum;
}