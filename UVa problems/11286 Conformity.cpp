//11286 Conformity
//#define Q11286
#ifdef Q11286

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int tc,id;
    while(cin >> tc && tc){
        map<set<int>,int>mp;

        while(tc--){
            set<int>ids;
            for(int i=0; i<5; i++) {
                cin >> id;
                ids.insert(id);
            }
            ++mp[ids];
        }
        int maxx=0;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            maxx = max(maxx,it->second);
        }
        int ans=0;
        for(auto it1=mp.begin(); it1!=mp.end(); it1++){
            if(it1->second == maxx) ans+=maxx;
        }
    cout << ans << endl;
    }

    return 0;
}


#endif

