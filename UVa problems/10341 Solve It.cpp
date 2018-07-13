//  #define Q10341
#ifdef Q10341

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9

int p,q,r,s,t,u;
double can(double x){
    return ((p*(exp(-x))+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2.0)+u));

}
int main(){
    ios::sync_with_stdio(0);
while(cin >> p >> q >> r >> s>> t >> u) {
    double low = 0, high = 1, mid = 0;
    if(can(0) < 0 || can(1) > EPS) {
        cout << "No solution\n";
        continue;
    }
    for (int i = 0; i < 30; i++) {
        mid = (low + high) / 2.0;
        //cerr << mid << endl;
        if (can(mid)>0) {
            low = mid;
        }
        else high = mid;
    }
    cout << fixed << setprecision(4) << mid << endl;
    }
    return 0;
}

#endif