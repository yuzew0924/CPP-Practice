#include <iostream>
#define LL long long
using namespace std;
LL n,l,r;
int main(int argc, char *argv[]) {
	cin >> n >> l >> r;
	int x = l/n;
	long long ans = (x+1)*n-1;
	long long cnt = n-1;
	bool small = false, large = false;
	while(cnt != 0){
		if(ans >= l && ans <= r) break;
		else if(ans <= l){
			ans += n;
			small = true;
		}else if(ans >= r){
			ans -= n;
			large = true;
		}
		if(small && large){
			ans -= 1;
			cnt -= 1;
			small = false;
			large = false;
		}
	}
	cout << cnt;
}