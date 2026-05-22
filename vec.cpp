#include <iostream>
#include <vector>
using namespace std;
vector<int> v; 
int main(int argc, char *argv[]) {
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for(int i=0;i<v.size();i++) cout << v[i] << endl;
	//for(auto i:v) v.erase(i);
	for(int i=0;i<v.size();i++) cout << v[i] << endl;

}