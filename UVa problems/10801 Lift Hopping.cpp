//#define Q10801
#ifdef Q10801

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
vi par;

int main(){
    ios::sync_with_stdio(0);
    int n,k,a;

    while(cin >> n >> k){
        adjlist.clear();
        adjlist.resize(100);
        vi elev;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            elev.push_back(a);
        }
        cin.ignore();
        string str;
        //int mx = -1;
        map<int,int> elevnum;
        for (int j = 0; j < n; ++j) {
            getline(cin, str);
            stringstream ss(str);
            int t; vi indx;

            while(ss >> t) {
                indx.push_back(t);
                //if(mx < t) mx = t;
                if(elevnum.find(t) != elevnum.end()) elevnum[t] = -1;
                else
                    elevnum[t] = j;
                //if(t == k) exist = true;
            }
            for (int i = 0; i < indx.size() ; ++i) {
                for (int l = i+1; l <indx.size(); ++l) {
                    adjlist[indx[i]].push_back(ii(elev[j] * (indx[l] - indx[i]), indx[l]));
                    adjlist[indx[l]].push_back(ii(elev[j] * (indx[l] - indx[i]), indx[i]));
                }
            }
        }
            vi dist(100, inf);
            dist[0] = 0;
            par.clear();
            par.resize(100, -1);
            priority_queue<ii, vii, greater<ii>> pq;
            pq.push(ii(0, 0));
            while (!pq.empty()) {
                ii front = pq.top();

                int d = front.first, u = front.second;
                if (u == k) break;
                pq.pop();
                if (d > dist[u]) continue;
                for (int i = 0; i < adjlist[u].size(); ++i) {
                    ii v = adjlist[u][i];
                    if (dist[v.second] > v.first + dist[u] + (u == 0 ? 0 : 60)) {
                        dist[v.second] = v.first + dist[u] + (u == 0 ? 0 : 60);
                        pq.push(ii(dist[v.second], v.second));
                    }

                }
            }

        if(dist[k] == inf) cout <<"IMPOSSIBLE\n";
        else cout << dist[k] << endl;

    }

    return 0;
}

#endif