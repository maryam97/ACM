#define Q701
#ifdef Q701

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    long long int n;
    while(cin >> n){
        int dig = (int)log10(n)+1;
        int dig2 = dig;
        int ans;
        bool yes = false;
        int  mx = (int)log10(2147483648) + 1;
        while(dig2++){
            //if(dig > mx) break;
            long long int num = pow(2.0,dig2);
            int d = (int)log10(num)+1;
            if(d <= 2*dig) continue;
            long long int div = (int)pow(10.0,d-dig);
            if((num/div) == n) {
                ans = dig2;
                yes = true;
                break;
            }

        }
        if(yes) cout << ans << endl;
        else cout << "no power of 2\n";

    }

    return 0;
}

#endif