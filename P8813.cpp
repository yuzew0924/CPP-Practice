#include <iostream>
#include <cmath>
using namespace std;
long long a,b;
int main(int argc, char *argv[]) {
	cin >> a >> b;
	long long cnt = 1;
	if(a == 1){
		cout << 1;
		return 0;
	}
	for(int i=1;i<=b;i++){
		cnt = cnt * a;
		if(cnt > (long long)1e9){
			cout << -1;
			return 0;
		}
	}
	cout << cnt;
}