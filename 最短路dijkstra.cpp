#include<iostream>
#include<queue>
using namespace std;
const long long INF = 2147483647;
const int N = 100000 + 5;
const int M = 5e6 + 5;
int head[M], cnt, dist[N], n, m, s;
bool vis[N];

struct qwq{ int v, next, c; } edge[M];
inline void add(int x, int y, int c) { edge[++cnt] = (qwq){ y, head[x], c}, head[x] = cnt;}
priority_queue< pair<int, int> > q;
void dijkstra(){
	for(int i=1;i<=n;i++){
		dist[i] = INF;
	}
	memset(vis,0,sizeof(vis));
	dist[s] = 0;
	q.push(make_pair(0,s));
	while(q.size()){
		int u = q.top().second; q.pop();
		if(vis[u]) continue; vis[u] = 1;
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
	cin >> n >> m >> s;
	memset(head, -1, sizeof(head));
	for(int i=1;i<=m;i++){
		int x, y, z;
		cin >> x >> y >> z;
		add(x,y,z);
	}
	dijkstra();
	for(int i = 1;i <=n;i++) cout << dist[i] << " ";
	
	return 0;
}