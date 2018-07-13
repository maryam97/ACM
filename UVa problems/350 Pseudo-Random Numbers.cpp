//
// Created by maryam on 9/19/17.
//
//#define Q350
#ifdef Q350

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
int z, m, i;
int f(int l){
    int ans = (((z * l) + i) % m);
    return ans;
}

ii findcycle(int x0){
    int t = f(x0), h = f(f(x0));
    while(t != h){
        t = f(t);
        h = f(f(h));}
    h = x0;
    int mu = 0;
    while(t != h){ t = f(t); h = f(h); mu++;}
    int lambda = 1;
    h = f(t);
    while(t != h){ h = f(h); lambda++;}
    return ii(mu, lambda);
}
int main(){
    ios::sync_with_stdio(0);
    int l, tc = 0;
    while(cin >> z >> i >> m >> l && (z || m || i || l)){
        cout << "Case " << ++tc << ": " << findcycle(l).second << endl;
    }

    return 0;
}


#endif
