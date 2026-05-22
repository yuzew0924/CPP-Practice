#include <iostream>
#include <set>

using namespace std;
int n, a;
set<int> s1, s2;
int main(int argc, char *argv[]) {
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a;
		s1.insert(a);
	}
	if(s1.size() != n) s1.insert(0);
	if(s1.size() <= 2){
		cout << -1;
		return 0;
	}
	for(auto i: s1)
		for(auto j: s2)
			s2.insert(i%j);
	cout << endl;
			
	return 0;
}