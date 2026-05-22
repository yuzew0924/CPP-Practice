#include <iostream>

using namespace std;
string arr[4] = {"A", "B", "C", "D"};

bool brr[4];
int cnt = 0;

void find(int n, string now){
	if(n >= 4){
		cout << now << endl;
		cnt++;
		return ;
	}
	for(int i = 0; i <= 3; i++){
		if(brr[i]){
			brr[i] = 0;
			find(n+1, now + arr[i]);
			brr[i] = 1;
		}
	}
}

int main(int argc, char *argv[]) {
	memset(brr, 1, sizeof(brr));
	string a = "";
	find(0, a);
	cout << cnt;
}