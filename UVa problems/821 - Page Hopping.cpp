//#define Q821
#ifdef Q821

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define inf 1000000
vvi adjmat;
int main(){
    ios::sync_with_stdio(0);
    int V,a,b,Case=0;

    while(cin >> a >> b && (a||b) ) {
        int cont = 0;
        Case++;
        adjmat.clear();
        adjmat.resize(110, vi(110,inf));
        map<int,int>num;

        if(num[a] == 0) num[a] = ++cont;
        if(num[b] == 0) num[b] = ++cont;
        adjmat[num[a]][num[b]] = 1;
        while(cin >> a >> b && (a||b)) {

            if(num[a] == 0) num[a] = ++cont;
            if(num[b] == 0) num[b] = ++cont;
            adjmat[num[a]][num[b]] = 1;
        }
        V = cont;
        //cerr << " v " << V << endl;
        for (int k = 1; k <= V; ++k) {
            for (int i = 1; i <= V; ++i) {
                for (int j = 1; j <= V; ++j) {
                    adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
                }
            }
        }
        int ans = 0, count = 0;
        for (int j = 1; j <= V; ++j) {
            for (int i = 1; i <= V; ++i) {
                if (i!=j) {
                    ans += adjmat[j][i];
                    ++count;
                }
            }
        }
        cout << "Case "<< Case <<": average length between pages = ";
        cout << fixed << setprecision(3) <<  (double)ans / count <<" clicks" << endl;
    }

    return 0;
}
#endif