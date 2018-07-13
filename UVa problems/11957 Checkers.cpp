//#define Q11957
#ifdef Q11957

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
vvi adjlist;
vvi vis;
vii order;
vvc graph;
int n;
int dx[] = {1,1}, dy[] = {-1,1};
int dx2[] = {2,2}, dy2[] = {-2,2};
/*void toposort(int i,int j){
    vis[i][j] = 1;
    for (int k = 0; k < 2; ++k) {
        if(i+dx[k] >= 0 && i+dx[k] < n && j+dy[k] >= 0 && j+dy[k] < n){
            if(graph[i+dx[k]][j+dy[k]] == 'B') {
                if(i+dx2[k] >= 0 && i+dx2[k] < n && j+dy2[k] >= 0 && j+dy2[k] < n)
                    if(graph[i+dx2[k]][j+dy2[k]]!='B' && !vis[i+dx2[k]][j+dy2[k]])
                        toposort(i+dx2[k],j+dy2[k]);
            }
            else{
                if(!vis[i+dx[k]][j+dy[k]]) toposort(i+dx[k], j+dy[k]);
            }
        }
    }
    order.push_back(ii(i,j));
}*/

int main(){
    ios::sync_with_stdio(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n;
        graph.clear();
        graph.resize(n,vc(n));
        vector<vector<llu>> ways(n,vector<llu>(n,0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> graph[i][j];
                if(graph[i][j] == 'W') ways[i][j] = 1;
            }
        }
        vis.clear(); vis.resize(n,vi(n,0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][j] == 'B') continue;
                for (int k = 0; k < 2; ++k) {
                    if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < n) {
                        if(graph[i+dx[k]][j+dy[k]] == 'B' && (i + dx2[k] >= 0 && i + dx2[k] < n && j + dy2[k] >= 0 && j + dy2[k] < n))
                            ways[i][j] += ways[i+dx2[k]][j+dy2[k]];
                        else
                            ways[i][j] += ways[i + dx[k]][j + dy[k]];
                    }
                }
                /*for(int k = 0; k < 2; ++k){
                    if (i + dx2[k] >= 0 && i + dx2[k] < n && j + dy2[k] >= 0 && j + dy2[k] < n) {
                            ways[i][j] += ways[i+dx2[k]][j+dy2[k]];
                    }
                }*/
                ways[i][j] %= 1000007;
            }
        }
        llu ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += ways[0][i];
        }

        //toposort(I,J);
        /*vii revorder; for(int i = order.size()-1; i >= 0; i--) {
            revorder.push_back(order[i]);
            //cout << order[i].first <<"," << order[i].second <<"    ";
        }//cout << endl;
*/

        /*for (int i = 0; i < revorder.size(); ++i) {
            cout << revorder[i].first <<"," << revorder[i].second << "  ";
        }cout << endl;*/

        /*for (int l = 0; l < revorder.size(); ++l) {
            int i = revorder[l].first, j = revorder[l].second;
            if(i==0) ans+=ways[i][j];
            for (int k= 0; k < 4; ++k) {
                if(i+dx[k] >= 0 && i+dx[k] < n && j+dy[k] >= 0 && j+dy[k] < n){
                    if(graph[i+dx[k]][j+dy[k]] == 'B') {
                        if(i+dx2[k] >= 0 && i+dx2[k] < n && j+dy2[k] >= 0 && j+dy2[k] < n)
                            if(graph[i+dx2[k]][j+dy2[k]]!='B')
                                ways[i+dx2[k]][j+dy2[k]] += ways[i][j];
                    }
                    else  ways[i+dx[k]][j+dy[k]] += ways[i][j];
                }
            }
        }*/



        cout << "Case " << t << ": " << ans%1000007 << endl;
        
    }


    return 0;
}

#endif