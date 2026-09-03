#include<iostream>
#include<queue>
using namespace std;
#define rep(i,m) for(int i = 1; i<=m; i++)
#define REPG(i,h,x) for(int i = h[x]; ~i; i = edge[i].next)

const int N = 1e5+5;

int head[N*10], cnt, n, m;
bool vis[N];

struct node{
	int x,y;
} b[N*10];

struct qwq{ int v, next, c; } edge[N * 10];

inline void add(int x, int y, int c) { edge[++cnt] = (qwq){ y, head[x], c}, head[x] = cnt;}


void find(int t){
	printf("%d ", t);
	vis[t] = 1;
	REPG(i, head, t){
		int y = edge[i].v;
		if(vis[y]) continue;
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
	for (int i = head[u]; i; i = edge[i].next) dfs(edge[i].v);
}

int main(){
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	rep(i,m){
		int x, y;
		cin >> b[i].x >> b[i].y;
		add(b[i].x, b[i].y, 1);
	}
	bfs();
	
	
	return 0;
}
