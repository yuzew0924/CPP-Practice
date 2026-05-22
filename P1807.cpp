#include<iostream>
#include<queue>
using namespace std;
const int INF = 2147483647;#define REPG(i,h,x) for(int i = h[x]; ~i; i = edge[i].next)

const int N = 1555;
const int M = 5e4+40;
int head[M], cnt, dist[N], n, m, s;
bool vis[N];

struct qwq{ int v, next, c; } edge[M];
inline void add(int x, int y, int c) { edge[++cnt] = (qwq){ y, head[x], c}, head[x] = cnt;}

void dijkstra(){
	queue< pair<int, int> > q;
	for(int i=1;i<=n;i++){
		dist[i] = -INF;
	}
	memset(vis,0,sizeof(vis));
	dist[1] = 0;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int u = q.front().second; q.pop();
		for(int i = head[u]; ~i; i = edge[i].next){
			int v = edge[i].v, z = edge[i].c;
			if(dist[v] < dist[u] + z){
				dist[v] = dist[u] + z;
				q.push(make_pair(dist[v], v));
			}
		}
	}
}

int main(){
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	for(int i=1;i<=m;i++){
		int x, y, z;
		cin >> x >> y >> z;
		add(x,y,z);
	}
	dijkstra();
	if(dist[n]==-INF) cout << "-1";
	else cout << dist[n];
	
	return 0;
}