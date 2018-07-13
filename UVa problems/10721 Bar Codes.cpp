//#define Q10721
#ifdef Q10721

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,K,M;
ll memo[51][51][51];
ll ways(int n,int k){
    if(n==0 && k==0) return 1;
    if(n>=1 && k==0) return 0;
    if(n<0) return 0;

    ll &ans=memo[n][k][M];
    if(ans!=-1) return ans;
    ans=0;
    for (int i = 1; i <= M; ++i) {
            ans+=(ways(n-i,k-1));
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    memset(memo,-1,sizeof memo);
    while(cin >> N >> K >> M){
        cout << ways(N,K) <<endl;
    }

    return 0;
}

#endif