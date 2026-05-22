#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
//f(k,w)：当背包容量为w，现有k件物品可以偷的最大价值 
int f[111][1111]; 

struct bag{
	int t,c;
} arr[1111];

int t,m; 

int main(){
	cin >> t >> m;
	for(int i=1;i<=m;i++){
		cin >> arr[i].c;
		arr[i].t = arr[t].c;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=t;j++){
			if(arr[i].t > j){
				f[i][j] = f[i-1][j];
			}else{
				f[i][j] = max(f[i-1][j], f[i-1][j-arr[i].t]+arr[i].c);
			}
		} 
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << f[i][j] << " ";
		}
		cout << endl;
	} */
	cout << f[m][t];

	return 0;
}
