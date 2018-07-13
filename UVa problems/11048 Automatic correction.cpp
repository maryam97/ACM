//
// Created by maryam on 9/6/17.
//
//#define Q11048
#ifdef Q11048

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n; cin >> n;
    string str;
    vector<string>vec;
    vector<string>query;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        vec.push_back(str);
    }
    int q; cin >> q;
    for (int j = 0; j < q; ++j) {
        cin >> str;
        //query.push_back(str);
        for (int i = 0; i < n; ++i) {
            int cmp = str.compare(vec[i]);
            if(cmp < 0) cout << str << " < \n";
            else cout << str << " > \n";
        }
    }


    return 0;
}

#endif
