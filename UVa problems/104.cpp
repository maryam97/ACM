//#define Q104
#ifdef Q104

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<double> vd;
typedef vector<int> vi;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
#define inf 1000000

vvvi p;

int main(){

    ios::sync_with_stdio(0);

    int n;
    while(cin >> n){
        vvvd adjmat(n + 1 , vvd (n + 1 , vd(n+1)));
        //vvd tmp(n+1 , vd (n+1 , 0));
        p.clear();
        p.resize(n + 1 , vvi(n + 1,vi(n+1)));

        for (int i = 0; i < n; ++i)
            adjmat[i][i][0] = 1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                p[i][j][0] = i;

        for (int j = 0; j < n ; ++j)
            for (int i = 0; i < n ; ++i)
                if(i != j) {
                    cin >> adjmat[j][i][0];
                }


        for (int step = 0; step < n; ++step) {
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (adjmat[i][j][step] < adjmat[i][k][step-1] * adjmat[k][j][0]) {
                            adjmat[i][j][step] = adjmat[i][k][step-1] * adjmat[k][j][0];
                            p[i][j][step] = k;
                        }
                    }
                }
            }
        }
        int ans = -1,s;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(adjmat[j][j][i] > 1.01) {
                    ans = j;
                    s = i;
                    break;
                }
            }
            if(ans != -1) break;
        }
        if(ans == -1) cout << "no arbitrage sequence exists\n";
        else {
            vi answer;
            answer.push_back(ans);
            cerr << ans << endl;
            int tmp = ans;
            for (int i = s; i >= 0; i--) {
                tmp = p[ans][tmp][i];
                cerr << "t: " << tmp << endl;
                answer.push_back(tmp);
            }
            cout << answer.back() + 1;
            for (int i = s; i >= 0; i--) {
                cout << " " << answer[i] + 1;
            }
            cout << endl;
        }

    }

    return 0;
}

#endif