//#define Q108
#ifdef  Q108

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n;
    while(cin>>n){
        vector<vector<int>>vec(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for (int j = 0; j < n; ++j) {
                cin>>vec[i][j];
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 1; i < n; ++i) {
                vec[k][i]+=vec[k][i-1];
            }
        }
        int MX=1e-9;
        for (int l = 0; l < n; ++l) {

            int sum=0;
            if( l>0) {
                for (int i = l; i < n; ++i) {
                    sum=0;
                    for (int j = 0; j < n; ++j) {
                        sum += vec[j][i] - vec[j][l - 1];
                        MX = max(sum, MX);
                        if (sum < 0) sum = 0;
                    }
                }
            }
            else{
                for(int i=0;i<n;i++) {
                    sum=0;
                    for (int j = 0; j < n; j++) {
                        sum += vec[j][i];
                        MX = max(sum, MX);
                        if (sum < 0) sum = 0;
                    }
                }
            }
        }
        cout<<MX<<endl;
    }

    return 0;
}

#endif