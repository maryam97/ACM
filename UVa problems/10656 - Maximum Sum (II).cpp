//#define Q10656
#ifdef Q10656

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n,num;

    while(cin >> n && n){
        vector<int>ans;
        for (int j = 0; j < n; ++j) {
            cin >> num;
            if (num) ans.push_back(num);
        }
        if(ans.size()==0) cout << "0\n";
        else {
            for (int i = 0; i < ans.size() - 1; ++i) {
                cout << ans[i] << " ";
            }
            cout << ans[ans.size() - 1] << endl;
        }
    }

    return 0;
}

#endif