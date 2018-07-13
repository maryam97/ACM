//#define Q216
#ifdef Q216

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
double inf =1e9;
vvd dist;
double memo[9][1024];
int par[9][1<<9];
vi X,Y;
int n;
double dis(int i, int j){
    double x=X[i] - X[j];
    double y=Y[i] - Y[j];
    return hypot(x,y)+16;
}
double tsp(int pos,int mask){
    if(mask == ((1 << n) - 1)) return /*dist[pos][0]*/0;
    if(memo[pos][mask] >= 0) return memo[pos][mask];
    double ans = inf;
    int p = -1;
    for (int next = 0; next < n; ++next) {
        if (/*next != pos && */!(mask & (1 << next) )) {
            double tmp = tsp(next, mask|(1 << next))+/*dist[pos][next]*/dis(pos,next);
            if(tmp < ans) {
                ans = tmp;
                p = next;
            }
        }


    }
    memo[pos][mask] = ans;
    par[pos][mask] = p;
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    int count=0;
    while(cin >> n && n){
        cout << "**********************************************************\n";
        cout << "Network #"<<++count << endl;
        dist.clear();
        dist.resize(n,vd(n));
        memset(memo,-1,sizeof memo);
        X.clear();X.resize(n);
        Y.clear();Y.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> X[i] >> Y[i];
        }
        for (int j = 0; j < n; ++j) {
            for (int i = j+1; i < n; ++i) {
                dist[j][i]= dist[i][j] = dis(j,i);
                //cerr << "dist " << j << "  " << i <<"  ->   "<< dist[j][i] << endl;
            }
        }

        double ans = inf; int id =-1;
        for (int k = 0; k < n; ++k) {
            double val = tsp(k,(1<<k));
            //cerr << val << endl;
            if(val < ans) ans = val,id=k;
        }
        //id=0;
        //cerr << id << endl;
        int msk=0;
        while(--n) {
                msk |= (1 << id);
            if(dis(id,par[id][msk])!=16) {
                printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", X[id], Y[id], X[par[id][msk]], Y[par[id][msk]], dis(id, par[id][msk]) );
                id = par[id][msk];
            }
        }
        printf("Number of feet of cable required is %.2lf.\n",ans);
    }

    return 0;
}

#endif