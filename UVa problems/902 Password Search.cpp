//
// Created by maryam on 9/5/17.
//
//#define Q902
#ifdef Q902

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n;
    string str, ans;

    while(cin >> n >> str){
        map <string, int> num;
        int mx = -1;
        for (int i = 0; i < str.size() - n + 1; ++i) {
            string s = "";
            for (int j = 0; j < n; ++j) {
                s += str[i+j];
            }
            num[s]++;
            if(num[s] > mx){
                mx = num[s];
                ans = s;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

#endif