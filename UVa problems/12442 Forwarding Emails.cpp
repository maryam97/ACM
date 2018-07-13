//#define Q12242
#ifdef Q12242

#include <bits/stdc++.h>
using namespace std;
int N;
vector<int>adj;
vector<int>memo;
vector<int>vis;

int dfs(int u){
    vis[u] = 1;
    int tmp=0;
    if((adj[u] != -1) && (!vis[adj[u]]))  tmp = tmp + dfs(adj[u])+1;
    vis[u] = 0;
    memo[u] = tmp;
    return tmp;
}

int main(){
    ios::sync_with_stdio(0);
    int T;cin >> T;
    int x,y;

   for (int i=0; i<T; i++){
        cin >> N;
       adj.clear();memo.clear();
       adj.resize(N,-1);
       memo.resize(N,-1);
       vis.clear(); vis.resize(N,0);
       for (int j = 0; j < N; ++j) {
           cin >> x >> y;
           x--;y--;
           adj[x]= y;
       }
       int mx = -1;
       int ans = -1;
       for (int l = 0; l < N; ++l) {
           if(memo[l] == -1)
               dfs(l);
           if(memo[l] > mx){
               mx = memo[l];
               ans = l+1;
           }
       }
       cout << "Case " << i+1 << ": " << ans << endl;
    }

    return 0;
}


#endif