//
//  main.cpp
//  P6070
//
//  Created by YZ Wang on 2023/7/20.
//

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int n,t;
string s, id, type, ti;
int arr[55];

long long toId(string two){
    long long ten = 0;
    for(int i=two.length()-1;i>=0;i--){
        ten = ten + (two[i]-'0') * pow(2,two.length()-i-1);
    }
    return ten;
}

bool typeCheck(string ss, int x){
    if(x == 0){
        if(ss[0]-'0'==1 &&ss[1]-'0'==0) return true;
    }else{
        if(ss[0]-'0'==0 &&ss[1]-'0'==1) return true;
    }
    return false;
}

bool checkAns(string ans, int p){
    int c = 0, pos;
    for(int i=0;i<ans.length();i++){
        if(ans[i]-'0' == 1){
            c++;
            pos = i;
        }
    }
    if(c==1&&pos==arr[p]){
        return true;
    }
    return false;
}

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> t >> n;
    cin >> s;
    for(int i=0;i<s.length();i++){
        arr[i+1] = (int)s[i]-65;
    }
    for(int i=1;i<=n;i++){
        //if(i!=1) cout << endl;
        bool f = false;
        cin >> id;
        long long idd = toId(id);
        if(idd >= 1 && idd <= 10000){
            f = true;
        }
        int tt = id[id.length()-1] - '0';
        cin >> type;
        if(f){
            cout << "ID: " << idd << "\n";
            if(typeCheck(type,tt)){
                cout << "Type Correct\n";
            }else{
                cout << "Type Incorrect\n";
            }
        }else{
            cout << "Wrong ID\n\n";
        }
        int cnt = 0;
        for(int j=1;j<=n;j++){
            cin >> ti;
            if(f){
                if(checkAns(ti, j)){
                    cnt++;
                }
            }
        }
        if(f){
            cout << fixed << setprecision(1) << (double)cnt/n*100 << "\n\n";
        }
    }
    

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

