#include<iostream>
#include<queue>
using namespace std;

const long long INF = 2147483647;
const int N = 333;

int n,m,t;
int graph[N][N];


int main(){
	cin >> n >> m >> t;
	
	for(int i=1;i<=n;i++){
		for(int j = 1; j <= n;j++){
			graph[i][j] = INF;
		}
	}
	
	for(int i = 1;i <= m; i++){
		int x, y, c;
		cin >> x >> y >> c;
		graph[x][y] = c;
	}
	for(int i =1;i <= t; i++){
		int a,b;
		cin >> a >> b;
		
	}
	
	
	return 0;
}