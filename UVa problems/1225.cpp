//#define Q1225
#ifdef Q1225

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string ans;
        for (int i = 1; i <= n; ++i) {
            int a = i,b;
            while(a){
                ans.push_back((char(a%10 + 48)));
                a/=10;
            }
        }
        map<char,int> num;
        for (int j = 0; j < ans.size(); ++j) {
             ++num[ans[j]];
            //cerr << ans[j] << endl;
        }
        cout << num['0'];
        for (int k = 1; k <= 9; ++k) {
            cout << " " << num[char(k+48)];
        }cout << endl;
    }

    return 0;
}

#endif
