#include <iostream>

using namespace std;

const int N = 3e5+5;

int n;
int arr[N];
int ans[N], ansn = 0;
int main(int argc, char *argv[]) {
	cin >> n;
	getchar();
	string s;
	getline(cin, s);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if((int)s[i] - 48 == 1) cnt++;
		arr[i+1] = (int)s[i]-48;
	}
	if(n == cnt){
		cout << 1;
		return 0;
	}
	int day1 = 0;
	int day2 = 0;
	for(int i =1; i <= n ; i++){
		if(arr[i]) day1++;
		else break;
	}
	ans[ansn++] = day1;
	cout << day1 << endl;
	for(int i = n; i >= 1; i--){
		if(arr[i]) day2++;
		else break;
	}
	ans[ansn++] = day2;
	cout << day2 << endl;
	int now = 0;
	for(int i = day1+1; i <= n - day2;i++){
		if(now && !arr[i]){
			ans[ansn++] = now;
			now = 0;
		}
		if(arr[i]) now++;
	}
	int minn = ans[0], pos = 0;
	for(int i = 1; i < ansn; i++){
		if(minn > ans[i]){
			minn = ans[i];
			pos = i;
		}
	}
	
	return 0;
}