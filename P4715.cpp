#include<iostream>
using namespace std;
const int N = 1000;
int n, max1 = 0, max2 = 0, pos1, pos2;
int arr[N], brr[N];

int main(){
    cin >> n;
    n = pow(2,n)/2;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        if(arr[i] > max1){
            max1 = arr[i];
            pos1 = i;
        }
    }
    for(int i=1;i<=n;i++){
        cin >> brr[i];
        if(brr[i] > max2){
            max2 = brr[i];
            pos2 = i+n;
        }
    }
    
    if(max1 < max2) cout << pos1;
    else cout << pos2;
    
    return 0;
}