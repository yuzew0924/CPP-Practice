//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define rep(i,m) for(int i = 1; i<=m; i++)
#define REPG(i,h,x) for(int i = h[x]; ~i; i = edge[i].next)

const int N = 1e5+5;

int head[N];
int num[N];
//bool vis[N];
int cnt, n, m, maxn;

struct qwq{ int v, next, c; } edge[N];

inline void add(int x, int y, int c) { edge[++cnt] = (qwq){ y, head[x], c}, head[x] = cnt;}


void dfs(int now, int number){
	if(num[now]) return;
	num[now] = number;
	REPG(i, head, now){
		dfs(edge[i].v, number);
	}
}

int main(){
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	rep(i,m){
		int x,y;
		cin >> x >> y;
		add(y, x, 1);
	}

	for(int i=n;i>=1;i--){
		if(num[i]) continue;
		dfs(i, i);
	}
	for(int i=1;i<=n;i++) cout << num[i] << " ";
	
	return 0;
}