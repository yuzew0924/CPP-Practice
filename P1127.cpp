#include <iostream>
#include <map>
using namespace std;
const int N = 1111;

int n;
string arr[N], ans[N];
bool vis[N], ff = false;
map<char, int> m1, m2;

void dfs(char init, int cnt){
	if(ff) return;
	if(cnt == n){
		ff = true;
		cout << ans[1];
		for(int i=2;i<=n;i++) cout << "." << ans[i];
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i] && arr[i][0] == init){
			vis[i] = 1;
			cnt += 1;
			ans[cnt] = arr[i];
			dfs(arr[i][arr[i].length()-1], cnt);
			vis[i] = 0;
			cnt -= 1;
		}
	}
}


int main(int argc, char *argv[]) {
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		m1[arr[i][0]]++;
		m2[arr[i][arr[i].length()-1]]++;
	}
	sort(arr+1,arr+1+n);
	char f, l;
	for(char i = 'a';i <= 'z';i++){
		if(m1[i]-m2[i] == 1) f = i;
		else if(m2[i]-m1[i] == 1) l = i;
	}
	int pos = 1;
	for(int i=1;i<=n;i++){
		if(arr[i][0] == f && (arr[i][arr[i].length()-1] != l || m2[l] != 1)){
			pos = i;
			break;
		}
	}
	vis[pos] = 1;
	ans[1] = arr[pos];
	dfs(arr[pos][arr[pos].length()-1], 1);
	if(!ff) cout << "***";
}