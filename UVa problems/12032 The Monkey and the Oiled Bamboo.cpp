#define Q12032
#ifdef Q12032

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> rung(n);
        for (int i = 0; i < n; ++i) {
            cin >> rung[i];
        }
        int low = 0, high = 10000000, mid = 0, ans = 10000001;
        for (int j = 0; j < 40; ++j) {
            mid = (high + low) / 2;
            int k = mid, count = 0;
            for (int i = 1; i < n; ++i) {
                if(rung[i] - rung[i-1] > k) continue;
                if(rung[i] - rung[i-1] == k ) k--;
                count++;
            }
            if(count <= n) {
                ans = min(k , ans);
                high = mid;
            }
            else low = mid;
        }
        cout << ans << endl;
    }
    return 0;
}
#endif