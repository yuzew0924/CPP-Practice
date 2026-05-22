#include <iostream>
using namespace std;
const int N = 1000000;

int maxn = -1, n;
struct node{
	int l, r;
} arr[N];

void find(int x, int d){
	
	if(x == 0){
		maxn = max(maxn, d);
		return ;
	}
	
	find(arr[x].l, d+1);
	find(arr[x].r, d+1);
}


int main(int argc, char *argv[]) {
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i].l >> arr[i].r;
	}
	find(1,0);
	cout << maxn;
	
}