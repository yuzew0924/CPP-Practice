#include <iostream>
using namespace std;
const int N = 10000;
struct node{
	char lson, rson;
} arr[N];

int n;
char x, o;

void find(char x){
	if(x == '*') return ;
	cout << x;
	find(arr[x].lson);
	find(arr[x].rson);
}


int main(int argc, char *argv[]) {
	cin >> n;
	cin >> o >> arr[o].lson >> arr[o].rson;
	for(int i=2;i<=n;i++){
		cin >> x >> arr[x].lson >> arr[x].rson;
	}
	find(o);
}