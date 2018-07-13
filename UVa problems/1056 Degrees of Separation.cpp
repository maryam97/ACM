//#define Q1056
#ifdef Q1056

#include "bits/stdc++.h"
using namespace std;
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define inf 1000000
vvi adjmat;
int V;

void warshall(){

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if(adjmat[i][j] > adjmat[i][k] + adjmat[k][j]) {
                    adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    int rel,network = 0;
    string a,b;
    while(cin >> V >> rel && (V||rel)){
        int cont = -1;
        map<string,int> nums;
        adjmat.clear(); adjmat.resize(V+5,vi(V+5,inf));

        for (int k = 0; k < V; ++k) {
            adjmat[k][k] = 0;
        }
        for (int i = 0; i < rel; ++i) {
            cin >> a >> b;
            if(nums.find(a) == nums.end()) nums[a] = ++cont;
            if(nums.find(b) == nums.end()) nums[b] = ++cont;
            adjmat[nums[a]][nums[b]] = 1;
            adjmat[nums[b]][nums[a]] = 1;
        }
        warshall();

        int ans = -1;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                //cout << adjmat[i][j]<<"  ";
                ans = max(ans,adjmat[i][j]);
            }//cout<< endl;
        }

        cout << "Network "<< ++network << ": ";
        if(ans == inf) cout << "DISCONNECTED\n\n";
        else cout << ans << endl<<endl;
    }

    return 0;
}

#endif