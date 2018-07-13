//#define Q10827
#ifdef Q10827

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int tc;  cin>>tc;
    while(tc--){
        int n;  cin>>n;
        vector<vector<int>>vec(n*2,vector<int>(n*2));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>vec[i][j];
            }
        }
        for (int i = n; i < 2*n; ++i) {
            for (int j = 0; j < n; ++j) {
                vec[i][j]=vec[i-n][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = n; j < n*2; ++j) {
                vec[i][j]=vec[i][j-n];
            }
        }
        for (int i = n; i < n*2; ++i) {
            for (int j = n; j < n*2; ++j) {
                vec[i][j]=vec[i-n][j-n];
            }
        }
        for (int k = 0; k < vec.size(); ++k) {
            for (int i = 1; i < vec.size(); ++i) {
                vec[k][i]+=vec[k][i-1];
            }
        }
        int MX=1e-9;
        for (int l = 0; l < n; ++l) {

            int sum=0;
            if( l>0) {
                for (int i = l; i < l+n; ++i) {
                    sum=0;
                    for (int k = 0; k <n ; ++k) {
                        sum=0;
                        for (int j = k; j < k+n; ++j) {
                            sum += vec[j][i] - vec[j][l - 1];
                            MX = max(sum, MX);
                            if (sum < 0) sum = 0;
                        }
                    }
                }
            }
            else{
                for(int i=0;i<n;i++) {
                    sum=0;
                    for (int k = 0; k < n; ++k) {
                        sum=0;
                        for (int j = k; j < k+n; j++) {
                            sum += vec[j][i];
                            MX = max(sum, MX);
                            if (sum < 0) sum = 0;
                        }
                    }
                }
            }
        }
        cout<<MX<<endl;
    }
    return 0;
}

#endif