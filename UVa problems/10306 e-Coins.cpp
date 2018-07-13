//#define Q10306
#ifdef Q10306

#include <bits/stdc++.h>
using namespace std;
#define MX 307
int inf = 1e8;
int m,S,sumx,sumy;
vector<int>X(m),Y(m);
vector<vector<int>>memo;
vector<int>dp;
/*int change(int x, int y, int k){
    //if(S*S-(x*x)-(y*y)<0) return 0;
    if(S*S-(x*x)-(y*y)==0) return 0;
    if((x||y||k) && S*S-(x*x)-(y*y)>0) return 1;
    //if(S<0) return inf;
    //if(memo[x][y] < inf) return memo[x][y];
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        //memo[x][y] = min(memo[x][y],memo[x][y]+ change(X[i],Y[i]));
        ans += change(x+X[i],y+Y[i],k+1);
        //ans = min(ans,change(x+X[i],y+Y[i],k+1));
    }
    memo[x][y] = min(memo[x][y],ans);
    //memo[x][y] = ans;
    return memo[x][y] ;
}
/*int change(int val, int k){
    if(val == 0) return k;
    if(dp[val] < inf) return dp[val];
    int ans=0,tmp=0;
    for (int i = 0; i < m; ++i) {
        ans = change(val-(X[i]+Y[i]),k+1);
    }
    tmp = min(tmp,ans);
    return dp[val] = tmp;
}*/
int main(){
    ios::sync_with_stdio(0);
    int n;cin >> n;

    while(n--){
        cin >> m >> S;
        sumx = 0, sumy = 0;
        X.clear();X.resize(m);
        Y.clear();Y.resize(m);
        memo.clear();
        memo.resize(MX,vector<int>(MX,inf));
        for (int i = 0; i < m; ++i) {
            cin >> X[i] >> Y[i];
        }
        memo[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = X[i]; j <= S; ++j) {
                for (int k = Y[i]; k <= S; ++k) {
                    memo[j][k] = min(memo[j][k],memo[j-X[i]][k-Y[i]]+1);
                }
            }
        }
        int ans = inf;
        for (int l = 0; l <= S; ++l) {
            for (int i = 0; i <= S; ++i) {
                if(l*l+i*i==S*S) ans = min(ans,memo[l][i]);
            }
        }
        if(ans == inf) cout << "not possible\n";
        else cout << ans << endl;

    }

    return 0;
}

#endif