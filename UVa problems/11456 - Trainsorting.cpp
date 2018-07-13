//#define Q11456
#ifdef Q11456

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int tc,n,num;cin >> tc;
    int count=1;
    while(tc--){
        cin >> n;
        vector<int>seq(n);
        vector<int>tail1(n),tail2(n);
        for(int i=0; i<n; i++){
            cin >> seq[i];
        }
        int ans=0;
        for (int k = 0; k <n ; ++k) {
            int beg_len=0,end_len=0;
            for (int j = 0; j < n; ++j) {
                if (seq[j] >= seq[k]) {
                    int pos = lower_bound(tail1.begin(), tail1.begin() + beg_len, seq[j]) - tail1.begin();
                    tail1[pos] = seq[j];
                    if (pos + 1 > beg_len) beg_len = pos + 1;
                } else {
                    int pos = lower_bound(tail2.begin(), tail2.begin() + end_len, seq[j] * -1) - tail2.begin();
                    tail2[pos] = seq[j] * -1;
                    if (pos + 1 > end_len) end_len = pos + 1;
                }
            }
            ans = max(ans,beg_len+end_len);
        }
        cout << ans << endl;
    }

    return 0;
}

#endif