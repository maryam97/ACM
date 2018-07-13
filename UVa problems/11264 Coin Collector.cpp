//#define Q11264
#ifdef Q11264

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int tc,n; cin >> tc;
    while(tc--){
        cin >> n;
        vector<int>vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        int sum=1,coin=1;
        for (int j = 1; j < n-1; ++j) {
            if(sum+vec[j]<vec[j+1])
                sum+=vec[j],coin++;
        }
        if(sum < vec[n-1]) coin++;
        cout << coin << endl;

    }

    return 0;
}

#endif