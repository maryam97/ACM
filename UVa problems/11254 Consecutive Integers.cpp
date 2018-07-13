//
// Created by maryam on 9/4/17.
//
//#define Q11254
#ifdef Q11254

#include "bits/stdc++.h"
using namespace std;
typedef  long long ll;
int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n!=-1){
        ll r = (ll)sqrt(2 * n);
        double aa ; ll a = -1, b = 0;
        for (int i = r; i >= 1; --i) {
            aa = (double)((2 * n) + i - (i * i))/(double)(2 * i);
            if(aa - int(aa)== 0 ){
                a = (int)aa;
                b = i;
                break;
            }
        }
       // if(a == n)  r = n;
        cout << n << " = " << a << " + ... + " << a + b - 1 << "\n";
    }

    return 0;
}

#endif
