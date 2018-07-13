//#define Q10048
#ifdef Q10048

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<int> ufds;
vector<pair<double, ii>> graph;
vector<int>vis;
vector<vector<ii>>path;
int C,S,Q,src,dist,ans;
bool dfs(int u){
    vis[u] = 1;
    if(u==dist) return true;
    for (auto &e : path[u]) {
        if(!vis[e.first])
            if(dfs(e.first))
            {
                ans = max(ans,e.second);
                return true;
            }
    }
    return false;
}

void buildUfds(int n) {
    ufds.clear(); ufds.resize(n);
    for(int i = 0; i < n; i++) ufds[i] = i;
}

int findSet(int i) {
    return (ufds[i] == i) ? i : (ufds[i] = findSet(ufds[i]));
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

void joinSets(int i, int j) {
    int a = findSet(i), b = findSet(j);
    if (a < b) ufds[a] = b;
    else ufds[b] = a;
}

void kruskal() {
    //int cost = 0;

    for(int i = 0; i < graph.size() ; i++) {
        iii fr = graph[i];
        if(!isSameSet(fr.second.first, fr.second.second)) {
            path[fr.second.second].push_back(make_pair(fr.second.first,fr.first));
            path[fr.second.first].push_back(make_pair(fr.second.second,fr.first));
            //cost = fr.first;
            joinSets(fr.second.second, fr.second.first);
        }
    }
    //return cost;
}
int main(){
    ios::sync_with_stdio(0);
    int x,y,d,tc = 0;
    while(cin >> C >> S >> Q && (C||S||Q)){
        if(tc++) cout << endl;
        graph.clear();
        for (int i = 0; i < S; ++i) {
            cin >> x >> y >> d;
            graph.push_back(iii(d,ii(x-1,y-1)));
        }

        path.clear();path.resize(C);
        //graph.clear();graph.resize(C);
        buildUfds(C);
        sort(graph.begin(),graph.end());
        kruskal();
        /*for (int k = 0; k < path.size(); ++k) {
            for (int i = 0; i < path.size(); ++i) {
                cerr << path[k][i].first << " ";
            }cerr << endl;
        }*/
        cout << "Case #" << tc << endl;
        for (int j = 0; j < Q; ++j) {
            vis.clear();vis.resize(C,0);
            ans = -1;
            cin >> src >> dist;
            dist--,src--;
            dfs(src);
            if(ans == -1) cout << "no path\n";
            else
                cout << ans << endl;
        }
         //cout << endl;
    }


    return 0;
}



#endif