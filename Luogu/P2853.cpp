#include<iostream>
#include<queue>
using namespace std;
#define rep(i,m) for(int i = 1; i<=m; i++)
#define REPG(i,h,x) for(int i = h[x]; ~i; i = edge[i].next)

const int N = 1e5+5;

int head[N*10], cnt, sum[N*10];
bool vis[N];

struct qwq{ int v, next, c; } edge[N * 10];

inline void add(int x, int y, int c) { edge[++cnt] = (qwq){ y, head[x], c}, head[x] = cnt;}


void find(int t){
	//printf("%d ", t);
	sum[t]++;
	vis[t] = 1;
	REPG(i, head, t){
		int y = edge[i].v;
		if(vis[y]) continue;
		//sum[y]++;
		find(y);
	}
}

void bfs(){
	queue<int> p;
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	p.push(1); cout << 1 << " ";
	while(!p.empty()){
		int x = p.front(); p.pop();
		REPG(i, head, x){
			int y = edge[i].v;
			if(vis[y] == 0){
				printf("%d ", y);
				vis[y] = 1;
				p.push(y);
			}
		}
	}
}

void dfs(int u) {
	if (vis[u]) return;
	vis[u] = true;
	sum[u]++;
	for (int i = head[u]; i; i = edge[i].next) dfs(edge[i].v);
}

int k, n, m, ans[N];

int main(){
	cin >> k >> n >> m;
	memset(head, -1, sizeof(head));
	for(int i=1;i<=k;i++) cin >> ans[i];
	rep(i,m){
		int x, y;
		cin >> x >> y;
		add(x, y, 1);
	}
	for(int i=1;i<=k;i++){
		memset(vis,0,sizeof(vis));
		find(ans[i]);
	}
	int c = 0;
	for(int i=1;i<=n;i++){
		if(sum[i] ==k) c++;
	}
	cout << c;
	return 0;
}