#include <iostream>

using namespace std;
int arr[100];
int main(int argc, char *argv[]) {
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for(int i = 1;i <= s1; i++){
		for(int j = 1;j <= s2; j++){
			for(int k = 1;k <= s3; k++){
				arr[i+j+k]++;
			}
		}
	}
	int maxn = -1, ans;
	for(int i = 1; i <= s1 + s2 + s3; i++){
		if(arr[i] > maxn){
			maxn = arr[i];
			ans = i;
		}
	}
	cout << ans;
}