//#define Q927
#ifdef Q927

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--){
        int deg,c,d,k;
        cin >> deg;
        vector<int>coef(deg+1);
        for (int i = 0; i <= deg; ++i) {
            cin >> coef[i];
        }
        cin >> d >> k;
        int count = 0;
        long long sum = 0;
        for (int i = d; i <= k+d; i+=d) {
            sum+=i, count++;
            if(sum >= k)
                break;
        }
        long long ans = 0,sen = 1;
        for (int j = 0; j <= deg; ++j) {
            sen = 1;
            sen*=coef[j];
            for (int i = 0; i < j; ++i) {
                sen*=count;
            }
            ans += sen;
        }
        cout << ans << endl;
    }

    return 0;
}

#endif