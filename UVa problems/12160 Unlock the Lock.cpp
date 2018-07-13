//#define Q12160
#ifdef Q12160

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<set<int>> vsi;
typedef queue<int> qi;
typedef unsigned long long llu;
#define inf 1000000000

vsi adjlist;
int L,U,R;


int main(){
    ios::sync_with_stdio(0);
    int tc = 0;
    while(cin >> L >> U >> R && (L || U || R)){
        adjlist.clear();adjlist.resize(R*10000);
        vi buttons;
        for (int i = 0; i < R; ++i) {
            int a; cin >> a; buttons.push_back(a);
        }

        cout << "Case " << ++tc << ": ";
        bool fnd = false;
        vi dist(R*10000, inf);
        dist[L] = 0;
        qi q; q.push(L);
        while(!q.empty()){
            int fr = q.front(); q.pop();
            if(fr == U){
                cout << dist[fr] << endl;
                fnd = true;
                break;
            }
            for(auto i: buttons){
                int num = (i + fr)%10000;
                if(dist[num] == inf){
                    dist[num] = dist[fr]+1;
                    q.push(num);
                }
            }
        }


        if(fnd == false) cout << "Permanently Locked\n";

    }

    return 0;
}

#endif