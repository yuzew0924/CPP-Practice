#include <iostream>

using namespace std;
int arr[30];
int main(int argc, char *argv[]) {
	int n = 4;
	while (n--) {
		string x;
		getline(cin, x);
		for(int i = 0; i < x.length(); i++){
			int p = int(x[i]-64);
			if(p < 1 || p > 26) continue;
			arr[int(x[i])-64]++;
		}
	}
	int maxn = 0;
	for(int i = 1; i <= 26; i++){
		maxn = max(maxn, arr[i]);
	}
	for(int i = maxn; i >= 1; i--){
		for(int j = 1; j <= 26; j++){
			if(arr[j] >= i) cout << "*";
			else cout << " ";
			cout << " ";
		}
		cout << endl;
	}
	for(int i = 1; i <= 26; i++){
        cout << char(i+64);
        if(i != 26) cout << " ";
	}
}