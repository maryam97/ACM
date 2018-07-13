//#define Q907
#ifdef Q907

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef unsigned long long llu;
#define inf 1000000000
vvi dist;
vvi memo;
vi vec;
int N, K;
int go(int cur, int night_left){
    if(night_left == 0) return dist[cur][N+1];
    if(memo[cur][night_left] != -1) return memo[cur][night_left];
    int  ans = -1;
    for (int x = cur+1; x < N + 1; ++x) {
        int next = min(go(x,night_left-1),dist[x][cur]);
        ans = max(next,ans);

    }
    return memo[cur][night_left] = ans;
}
int main(){
    ios::sync_with_stdio(0);
    while(cin >> N >> K){
        dist.clear();
        dist.resize(N+2, vi(N+2));
        memo.clear();
        memo.resize(N+1,vi(K+1,-1));
        vec.clear();
        vec.resize(N+2,0);vec[0] = 0;
        for (int i = 1; i < N + 2; ++i) {
            cin >> vec[i];
        }
        for (int i = 0; i < N + 2; ++i) {
            for (int j = i+1; j < N + 2; ++j) {
                for (int k = i+1; k <= j; ++k) {
                    //if(i!=j)
                    dist[i][j] += (vec[k]);
                    dist[j][i] += vec[k];
                }
            }
        }
        cout << go(0,K) << endl;
    }

    return 0;
}

#endif