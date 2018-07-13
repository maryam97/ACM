//#define Q1225
#ifdef Q1225

#include "bits/stdc++.h"
using namespace std;

int sumOffac(int n){
    int ans = 1;
    for (int i = 2; i <= n / 2; ++i) {
        if(n % i == 0) ans += i;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    int n;
    cout << "PERFECTION OUTPUT\n";
    while(cin >> n && n) {
        int ans = sumOffac(n);
        //cout << ans << endl;
        string str;
        if(ans == n) str = "PERFECT";
        else if(ans > n) str = "ABUNDANT";
        else if(ans < n) str = "DEFICIENT";
        if(n == 1) str = "DEFICIENT";
        cout << right << setw(5) << n << "  " << str << endl;
    }
    cout << "END OF OUTPUT\n";
    return 0;
}

#endif