//#define Q575
#ifdef Q575

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    string str;
    while(cin >> str && str !="0"){
        int n = str.size();
        long long int ans = 0;
        for (int i = 0; i < str.size(); ++i) {
            ans += ((str[i] - '0') * (pow(2.0,n) - 1));
            n--;
        }
        cout << ans << endl;
    }
    return 0;
}
#endif