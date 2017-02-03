//define Q10189
#ifdef Q10189

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int line,colmn;
    int dx[8] = {-1,0,1,-1,1,-1,0,1};
    int dy[8] = {1,1,1,0,0,-1,-1,-1};
    char c;
    int tc=0;
    while(cin >> line >> colmn && (line||colmn)){
        if(tc++) cout << endl;
        cout << "Field #" << tc <<":"<<endl;
        vector<vector<int>>arr(line,vector<int>(colmn));
        for (int i = 0; i < line; i++) {
            for (int j = 0; j < colmn; j++) {
                cin >> c;
                if(c == '*') {
                    arr[i][j] = -1;//cerr<<arr[i][j]<<"; ";
                    //else{
                    for (int k = 0; k < 8; k++) {
                        if (i + dx[k] >= 0 && i + dx[k] < line && j + dy[k] >= 0 && j + dy[k] < colmn)
                            if (arr[i + dx[k]][j + dy[k]] != -1) ++arr[i + dx[k]][j + dy[k]];//cerr<<arr[i][j]<<"; ";
                        //}
                    }
                }
            }
        }
        for (int l = 0; l < line; l++) {
            for (int i = 0; i < colmn; i++) {
                if(arr[l][i] == -1) cout <<"*";
                else cout <<arr[l][i];
            }
            cout << endl;
        }
    }

    return 0;
}

#endif