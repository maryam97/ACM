//#define Q10459
#ifdef Q10459

#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define inf 1000000
vvi adj;
vi visit;
int n;int height;
set<int> worst,ans;

void dfs2(int v, int d){
    visit[v] = 1;
    for(auto &e: adj[v]){
        if(!visit[e]) {
            height = max(height, d + 1);
            dfs2(e, d + 1);
        }
    }
}
void dfs( int v, int x, int h){
    visit[v] = 1;
    for(auto & e: adj[v])
        if(!visit[e])
        {
            if(h+1 == x) {
                worst.insert(e);
            }
            dfs(e,x,h+1);
        }
}

int main(){
    ios::sync_with_stdio(0);
    while(cin >> n){
        adj.clear();
        adj.resize(n);
        visit.clear(); visit.resize(n,0);
        set<int> best;
        worst.clear();ans.clear();
        for (int i = 0; i < n; ++i) {
           best.insert(i);
            int x,a;cin >> x;
            for(int j = 0; j < x; j++){
                cin >> a;
                a--;
                adj[i].push_back(a);
            }
        }
        vi vis(n,0);
        int num = n, c = 0, x=0;
        bool ok;
        while(num > 2) {
            x++;
            for (int i = 0; i < n; ++i) {
                c = 0, ok = true;
                if (!vis[i]) {
                    for (int j = 0; j < adj[i].size(); ++j) {
                        if (!vis[adj[i][j]]) ++c;
                        if(vis[adj[i][j]] == x) ok = false;
                    }
                    if (ok && c == 1) {
                        vis[i] = x;
                        num--;
                        set<int>::iterator it = best.find(i);
                        best.erase(it);
                    }
                }
            }
        }

        height = -inf;
        visit.clear(); visit.resize(n,0);
        set<int>::iterator it = best.begin();
        dfs2(*it,0);
        cout << "Best Roots  :";
        for(set<int>::iterator i = best.begin(); i != best.end(); i++) {
            cout << " " << *i+1;
            visit.clear();
            visit.resize(n,0);
            dfs(*i, height,0);
        }
        cout << endl;
        cout << "Worst Roots :";
        for(set<int>::iterator i = worst.begin(); i != worst.end(); i++) cout << " " << *i+1;
        cout << endl;
    }

    return 0;
}

#endif