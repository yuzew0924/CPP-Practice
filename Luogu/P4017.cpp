#include<iostream>
#include<queue>
using namespace std;
const int N = 5555;
const int mod = 80112002;
int n,m;
int mapp[N][N], indegree[N], outdegree[N], cnt[N];

int main(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int x, y;
		cin >> x >> y;
		if(!mapp[x][y]){
			mapp[x][y] = 1;
			indegree[y]++;
			outdegree[x]++;
		}
	}
	/*
	for(int i=1;i<=n;i++) cout <<outdegree[i] << " ";
	cout << endl;
	*/
	queue<int> t;
	for(int i=1;i<=n;i++) if(indegree[i] == 0) t.push(i), cnt[i]=1;
	/*
	for(int i=1;i<=n;i++) cout <<cnt[i] << " ";
	cout << endl;
	*/
	while(!t.empty()){
		int u = t.front(); t.pop();
		for(int i=1;i<=n;i++){
			if(mapp[u][i]){
				indegree[i]--;
				cnt[i] += cnt[u];
				cnt[i] %= mod;
				if(!indegree[i]) t.push(i);
			}
		}
	}
	/*
	for(int i=1;i<=n;i++) cout <<cnt[i] << " ";
	cout << endl;
	*/
	int x = 0;
	for(int i=1;i<=n;i++) if(outdegree[i]==0) x = (x+cnt[i])%mod;
	cout << x;
	
	return 0;
}