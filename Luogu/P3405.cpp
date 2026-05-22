#include <iostream>
#include <map>
using namespace std;
const int N = 2e5+5;
map<int, int> ma[N];
int n;
long long cnt;
int main(int argc, char *argv[]) {
	cin >> n;
	for(int i=1;i<=n;i++){
		string x, y;
		cin >> x >> y;
		int a = x[0]+x[1], b = y[0] + y[1];
		ma[a][b]++;
		cnt += ma[b][a];
		//cout << a << " " << b << endl;
	}
	cout << cnt;
}