#include <iostream>
#include <queue>
using namespace std;

struct piao{
	int time, price;
};
int n;
int t,p,ti;
long long cnt = 0;
vector<piao> v;
bool f;

int main(int argc, char *argv[]) {
	cin >> n;
	for(int i=1;i<=n;i++){
		f = false;
		cin >> t >> p >> ti;
		if(t == 0){
			piao temp;
			temp.time = ti, temp.price = p;
			v.push_back(temp);
			cnt += p;
		}else{
			for(auto j: v){
				if(ti - j.time > 45){
					q.pop();
				}
				if(ti - j.time <= 45 && j.price <= p){
					f = true;
					q.pop();
					break;
				}
			}
			if(!f) cnt += p;
		}
		//cout << cnt << endl;
	}
	cout << cnt;
}
// && 