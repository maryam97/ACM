//10443 Rock, Scissors, Paper
//#define Q10443
#ifdef Q10443

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<char>>vvc;
typedef vector<pair<int,int>>vii;
int main(){
    ios::sync_with_stdio(0);
    int tc;cin>>tc;
    int row,colmn,day;
    char c;
    vii neighbor = {{0,1},{-1,0},{1,0},{0,-1}};
    while(tc--){
        cin >> row >> colmn >> day;
        vvc RSP(row,vector<char>(colmn,'0'));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < colmn; ++j) {
                cin >> c;
                RSP[i][j] = c;
            }
        }
        vvc temp(row,vector<char>(colmn));
        temp = RSP;

        while(day--){
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < colmn; j++) {
                    for (auto &e : neighbor) {
                        if(i+e.first>=0 && i+e.first<row && j+e.second>=0 && j+e.second<colmn){
                            if(RSP[i][j] == 'R' && RSP[i+e.first][j+e.second] == 'P' )
                                temp[i][j] = 'P';
                            else if(RSP[i][j] == 'S' && RSP[i+e.first][j+e.second] == 'R')
                                temp[i][j] = 'R';
                            else if(RSP[i][j] == 'P' && RSP[i+e.first][j+e.second] == 'S')
                                temp[i][j] = 'S';
                        }
                    }
                }
            }
            RSP=temp;
        }
        for (int k = 0; k < row; k++) {
            for (int i = 0; i < colmn; i++) {
                cout << temp[k][i];
            }
            cout << endl;
        }
        if(tc) cout << endl;
    }

    return 0;
}


#endif