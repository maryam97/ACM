//
// Created by maryam on 9/29/17.
//
//#define Q10916
#ifdef Q10916

#include "bits/stdc++.h"
using namespace std;

int num(int n){
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += log2(i);
    }
    return (int)ans + 1;
}

int main(){
    ios::sync_with_stdio(0);
    map<int,int> bit;
    bit[1960] = 4;

    for (int i = 1970; i <= 2160; i+=10) {
        bit[i] = bit[i-10] * 2;
    }
    int n;
    while(cin >> n && n){
        n = (n/10) * 10;
        int i;
        int lo = 0, hi = bit[n];
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            int ans = num(mid);
            if(ans > bit[n])
                hi = mid - 1;
            else{
                i = mid;
                lo = mid + 1;
            }
        }
        cout << i << endl;
    }
    return 0;

}
#endif
