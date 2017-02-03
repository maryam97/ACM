//11572 Unique Snowflakes
//#define Q11572
#ifdef Q11572

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int tc,snow,id;
    cin >> tc;
    while(tc--){
        map<int,int>num;
        cin >> snow;
        while(snow--){
            cin>>id;
            ++num[id];
        }
        cout << num.size() <<endl;
    }

    return 0;
}

#endif