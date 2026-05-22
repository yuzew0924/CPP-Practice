#include <iostream>

using namespace std;
const int N = 1e5+5;

long long arr[2*N];
int n, m;

int main(int argc, char *argv[]) {
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> arr[i];
	}
	int low, high;
	while(m--){
		cin >> high;
		low = 1;
		for(int i = 1;i <= n; i++){
			if(arr[i] < low) continue;
			else if(arr[i] >= high){
				arr[i] += (high - low + 1);
				break;
			}
			else if(arr[i] >= low){
				int t = low;
				low = arr[i] + 1;
				arr[i] += (long long)(arr[i] - t + 1);
 			}
			//cout << arr[i] << " ";
		}
		//cout << endl;
	}
	for(int i = 1;i <= n; i++){
		cout << arr[i] << endl;
	}
}