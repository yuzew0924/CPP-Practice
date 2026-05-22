#include <iostream>

using namespace std;

int a, b, c;

int main(int argc, char *argv[]) {
	cin >> a >> b >> c;
	if((long long)a * a > (long long)b * c) cout << "Alice";
	else cout << "Bob";
}