//193 - Graph Coloring

//#define Q193
#ifdef Q193

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int n,m,sum,mx;
vii adjList;
vi color,ans;
void solve(int i){
    if(i < n){
        bool Black=true;
        for (int j = 0; j < adjList[i].size(); ++j) {
            if (color[adjList[i][j]] == 1)
                Black = false;
        }
        if(Black) {
            color[i] = 1;
            solve(i + 1);
            color[i] = 0;
            solve(i + 1);
        }
        else {
            color[i] = 0;
            solve(i + 1);
        }
    }
    else{
        sum = 0;
        for (int j = 0; j < color.size(); ++j) {
            if(color[j]==1) {
                sum++;
            }
        }
        if(sum > mx){
            ans.clear();
            for (int j = 0; j < color.size()    ; ++j) {
                if(color[j]==1) {
                    ans.push_back(j);
                }
            }
            mx = sum;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    int s,d;
    while(tc--){
        cin >> n >> m;
        mx=0;
        adjList.clear();
        adjList.resize(n);
        color.assign(n,0);
        for (int i = 0; i < m; ++i) {
            cin >> s >> d;
            adjList[s-1].push_back(d-1);
            adjList[d-1].push_back(s-1);
        }
        solve(0);
        cout << mx <<endl;
        for (int j = 0; j < ans.size()-1; ++j) {
            cout << ans[j]+1 <<" ";
        }cout << ans[ans.size()-1]+1 << endl;

    }

    return 0;
}

#endif