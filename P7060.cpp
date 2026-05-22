#include<bits/stdc++.h>
using namespace std;
map<int,int> dig {{0,6},{1,2},{2,5},{3,5},{4,4},{5,5},{6,6},{7,3},{8,7},{9,6}};

int n;
struct node{
	int dis;
	string str;
}Begin, Node;

string bfs(){
	queue<node> q;
	Begin.dis = 0;
	Begin.str = ""; 
	q.push(Begin);
	while(!q.empty()){
		node top = q.front();
		q.pop();
		int d = top.dis;
		string s = top.str;
		if(d == n && s.length() == 4){
			int h = atoi(s.substr(0,2).c_str());
			int m = atoi(s.substr(2,2).c_str());
			if(h >= 0 && h <= 24 && m >= 0 && m <= 59){
				return s.insert(2,":");
			}
		}
		for(int i=0;i<=9;i++){
			if(d + dig[i] <= n && s.length() < 4){
				Node.dis = d + dig[i];
				Node.str = s + to_string(i);
				q.push(Node);
				//cout << Node.dis << " " << Node.str << endl;
			}
		}
	}
	return "Impossible";
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n;
	cout << bfs();

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

