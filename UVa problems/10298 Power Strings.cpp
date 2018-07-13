//
// Created by maryam on 9/17/17.
//
//#define Q10298
#ifdef Q10298

#include "bits/stdc++.h"
using namespace std;
string T, P;
vector<int> b;
int n,m,ans;
void kmpProcess(){
    b.assign(n+1,0);
    int i = 0, j = -1; b[0] = -1;
    while(i < m){
        while(j >= 0 && P[i]!=P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void kmpSearch(){
    int i = 0, j = 0;
    while(i < n){
        while(j >= 0 && T[i]!=P[j]) j = b[j];
        i++; j++;
        if(j == m) {
            j = b[j];
            ans++;
        }

    }
    //return ans;
}

int main(){
    ios::sync_with_stdio(0);
    string s;
    while(cin >> s && s!="."){
        ans = -1;
        P = s;
        T = s + s;
        n = (int)T.length();
        m = (int)P.length();
        kmpProcess(); kmpSearch();
        cout << ans << endl;
    }

    return 0;
}


#endif
