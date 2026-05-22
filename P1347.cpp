#include <iostream>
#include <queue>
#define rep(i,m) for(int i = 1; i<=m; i++)
#define REPG(i,h,x) for(int i = h[x]; ~i; i = edge[i].next)
		
using namespace std;

const int N = 666;

int head[N], cnt, n, m, indegree[N], in[N];
bool brr[N];

struct qwq{ int v, next; } edge[N];

inline void add(int x, int y) { edge[++cnt] = (qwq){ y, head[x] }, head[x] = cnt;}

string re;
bool f = false;

bool checkCir(){
	for(int i=1;i<=n;i++) in[i] = indegree[i];
	queue<int> t;
	int sum = 0;
	//for(int i=1;i<=n;i++) cout << indegree[i] << " ";	
	for(int i=1;i<=n;i++) if(in[i] == 0) {t.push(i);}
	while(!t.empty()){
		int u = t.front(); t.pop();
		sum++;
		for(int i = head[u]; ~i; i = edge[i].next){
			int y = edge[i].v;			in[y]--;
			if(!in[y]){
				t.push(y);
				//cout << y << " " << sum << endl;
			}		}
		
	}
	//cout << sum << endl;
	if(sum == n) return true;
	return false;
}

bool checkAll(){
	for(int i=1;i<=n;i++) in[i] = indegree[i];
	int cc = 0;
	queue<int> t;
	for(int i=1;i<=n;i++) if(in[i] == 0) t.push(i);
	t.push(-1);
	while(!t.empty()){
		int u = t.front(); t.pop();
		if(u == -1) t.push(-1), u = t.front(), t.pop(), cc++;
		if(t.empty()) break;
		for(int i = head[u]; ~i; i = edge[i].next){
			int y = edge[i].v;			in[y]--;
			if(!in[y]){
				t.push(y);
				//cout << y << " " << sum << endl;
			}		}
	}
	//cout << cc << endl;
	if(cc==n) return true;
	return false;
}

void find(){
	for(int i=1;i<=n;i++) in[i] = indegree[i];
	queue<int> q;
	//for(int i=1;i<=n;i++) cout << indegree[i] << " ";
	for(int i=1;i<=n;i++) if(in[i] == 0) {q.push(i);}
	while(!q.empty()){
		int u = q.front(); q.pop();
		cout << char(u+64);
		for(int i = head[u]; ~i; i = edge[i].next){
			int y = edge[i].v;			in[y]--;
			if(!in[y]){
				q.push(y);
				//cout << y << " " << sum << endl;
			}		}
		
	}
	
}

int main(int argc, char *argv[]) {
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	rep(i,m){
		cin >> re;
		int x = re[0]-64, y = re[2]-64;
		add(x, y);
		indegree[y]++;
		//for(int i=1;i<=n;i++) in[i] = indegree[i];
		if(f) continue;
		if(!checkCir()){
			f = true;
			cout << "Inconsistency found after " << i << " relations.";
			continue;
		}
		//for(int i=1;i<=n;i++) in[i] = indegree[i];
		if(checkAll()){
			f = true;
			cout << "Sorted sequence determined after " << i << " relations: ";
			for(int i=1;i<=n;i++) in[i] = indegree[i];
			//int pos = getfa(1);
			find();
			cout << ".";
			continue;
		}
		
		
	}
	if(!f) cout << "Sorted sequence cannot be determined.";
	
	
}

/*
4 6
C<D
C<B
B<A
C<D
D<A
A<A
*/