//#define Q10054
#ifdef Q10054

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef unsigned long long llu;
#define inf 1000000000

vvii adjlist;
list<ii> cyc;

void eulertour(list<ii>::iterator i, int u){
    for (int j = 0; j < adjlist[u].size(); ++j) {
        ii &v = adjlist[u][j];
        if(v.second){
            v.second = 0;
            for (int k = 0; k < adjlist[v.first].size(); ++k) {
                ii &uu = adjlist[v.first][k];
                if(uu.first == u && uu.second) { uu.second = 0; break;}
            }
            eulertour(cyc.insert(i,ii(u,v.first)), v.first);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    int t,n,x,y;cin >> t;
    for (int T = 1; T <= t; ++T) {
        if(T > 1 ) cout << endl;
        cin >> n;
        adjlist.clear();
        adjlist.resize(51);
        map<int,int> deg;
        int st;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            st = x;
            deg[x]++; deg[y]++;
            adjlist[x].push_back(ii(y,1));
            adjlist[y].push_back(ii(x,1));
        }

        cout << "Case #" << T << "\n";

        auto t = deg.begin();
        int odds = 0;
        /*for (t; t!= deg.end(); t++) {
            if((t->second) % 2 != 0) ++odds;
        }*/
        for (int j = 0; j < 51; ++j) {
            if(adjlist[j].size() & 1 ) {odds = 1; break;}
        }
        if(odds) cout << "some beads may be lost\n";
        else {
            cyc.clear();
            auto it = cyc.begin();
            eulertour(it, st);
            //vi ans;
            /*auto i = cyc.begin();
            for (i; i != cyc.end(); i++) ans.push_back(*i);
            ans.push_back(ans[0]);
            reverse(ans.begin(),ans.end());
            for (int j = 0; j < ans.size()-1; j++) {
                cout << ans[j] << " " << ans[j+1] << endl;
            }*/
            for(auto i = cyc.rbegin() ; i != cyc.rend(); i++) cout << (*i).first <<" " << (*i).second << endl;

        }
    }


    return 0;
}


#endif