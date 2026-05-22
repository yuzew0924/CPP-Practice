#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

string ransomNote, magazine;

int main(){
	cin >> ransomNote >> magazine;
	int arr1[50], arr2[50];
	
	memset(arr1, 0, sizeof(arr1));
	memset(arr2, 0, sizeof(arr2));
	for(int i = 0; i < ransomNote.length(); i++){
		arr1[(int)ransomNote[i]-97]++;
	}
	for(int i = 0;i < magazine.length();i++){
		arr2[(int)magazine[i]-97]++;
	}
	for(int i = 0;i < 30;i++){
		cout << arr1[i] << " " << arr2[i] << endl;
		if(arr2[i] < arr1[i]){ cout << "false";}
	}
	
	cout << "true";
	

	return 0;
}
