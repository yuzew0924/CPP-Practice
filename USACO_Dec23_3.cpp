#include <iostream>

using namespace std;
const int N = 2e5+5;
int t;
int n, arr[N], brr[N], crr[N];

int main(int argc, char *argv[]) {
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		for(int i = 1; i <= n; i++){
			cin >> brr[i];
		}
		for(int i = 1; i <= n; i++){
			cin >> crr[i];
		}
	}
}