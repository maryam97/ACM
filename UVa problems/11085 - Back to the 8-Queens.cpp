//#define Q11085
#ifdef Q11085

#include <bits/stdc++.h>
using namespace std;
int mov = 0,ans=INT32_MAX;
vector<int>row(8);
vector<int>ROW(8);
int place(int r,int c){
    for (int prev = 0; prev < c; ++prev) {
        if(r==ROW[prev] || (abs(r-ROW[prev])==abs(c-prev))) return false;
    }
    return true;
}

int backtrack(int c){

    if(c==8) {
        for (int i = 0; i < 8; ++i) {
            if (row[i] != ROW[i]) mov++;
        }
        ans = min(ans, mov);
        mov = 0;
    }
    for (int r = 0; r < 8; ++r) {
        if(place(r,c)){
            ROW[c]=r;
            backtrack(c+1);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    int tc=0;
    /*while(1){

        for (int i = 0; i < 8; ++i) {
            cin >> row[i];
        }*/
    while(cin >> row[0] >> row[1] >> row[2] >> row[3] >> row[4] >> row[5] >> row[6] >> row[7]){
        for (int i = 0; i < 8; ++i) {
            row[i]--;
        }
        ROW.clear();ROW.resize(8,0);
        mov=0;
        ans=INT32_MAX;
        cout <<"Case "<<++tc << ": " << backtrack(0) << endl;
    }
    return 0;
}

#endif