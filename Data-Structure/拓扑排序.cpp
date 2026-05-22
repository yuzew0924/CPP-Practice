#include<iostream>
#include<queue>
using namespace std;
const int N = 1e3+50;
int n,m,p;
int a[N], b[N], c[N];
int mapp[N][N], indegree[N];

int main(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int h = 0;
		cin >> p;
		memset(b,0,sizeof(b));
		for(int j=0;j<p;j++) cin >> a[j], b[a[j]] = 1;
		for(int j=a[0]+1;j<a[p-1];j++){
			if(!b[j]) c[h++] = j;
		}
		for(int k=0;k<p;k++){
			for(int j=0;j<h;j++){
				int u = a[k], v = c[j];
				if(!mapp[u][v]){
					mapp[u][v] = 1;
					indegree[v]++;
				}
			}
		}
	}
	int cnt = 0;
	queue<int> t;
	for(int i=1;i<=n;i++) if(indegree[i] == 0) t.push(i);
	t.push(-1);
	while(!t.empty()){
		int u = t.front(); t.pop();
		if(u == -1) t.push(-1), u = t.front(), t.pop(), cnt++;
		if(t.empty()) break;
		for(int i=1;i<=n;i++){
			if(mapp[u][i]){
				indegree[i]--;
				if(!indegree[i]) t.push(i);
			}
		}
	}
	cout << cnt << endl;
	
	return 0;
}
/*
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
	
	for(int i=1;i<=n;i++) cout <<outdegree[i] << " ";
	cout << endl;
	
	queue<int> t;
	for(int i=1;i<=n;i++) if(indegree[i] == 0) t.push(i), cnt[i]=1;
	
	for(int i=1;i<=n;i++) cout <<cnt[i] << " ";
	cout << endl;
	
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
	
	for(int i=1;i<=n;i++) cout <<cnt[i] << " ";
	cout << endl;
	
	int x = 0;
	for(int i=1;i<=n;i++) if(outdegree[i]==0) x = (x+cnt[i])%mod;
	cout << x;
	
	return 0;
}
*/