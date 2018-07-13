//#define Q11413
#ifdef Q11413

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n,m,cap;

    while(cin >> n >> m){
        vector<int> vessel;
        while(n--){
            cin >> cap;
            vessel.push_back(cap);
        }
        int low=0, high=1000000000, mid=0,ans=1000000001;

        for (int i = 0; i < 30; ++i) {
            int mx = -1;
            mid = (high + low) / 2;
            int sum=0,container=1;
            for (int j = 0; j < vessel.size() ; j++) {
                if(container > m) {
                    break;
                }
                if(sum + vessel[j] <= mid) {
                    sum += vessel[j];
                    if(sum > mx) mx = sum;
                    //cout <<"mid: "<< mid << " mx:" << mx << " sum: " << sum <<" container: "<<container<< endl;
                }
                else{
                    ++container;
                    sum=0;
                    j--;
                }
            }
            if(container <= m /*&& ans > mx */) {
                high=mid;
                //cout << "hmmmmmmmmmmmmmmmmmmmmmmmmmmmm\n";
                if(ans > mx) ans = mx;
            }
            //else if(!check) high=mid;
            else low = mid;
        }
        cout << ans << endl;
    }

    return 0;
}

#endif