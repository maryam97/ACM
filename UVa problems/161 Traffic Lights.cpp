//161 Traffic Lights
//#define Q161
#ifdef Q161

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n,m,k;
    int curtime=0;
    vector<int>vec;
    while(cin >> n >> m  && n && m){
        vec.push_back(n);
        vec.push_back(m);
        while(cin >> k && k){
            vec.push_back(k);
        }
        sort(vec.begin(),vec.end());
        curtime = vec[0]+1;
        int ans=-1;
        for(int i = curtime; i<=18000; i++){
            int check=0;
            for(int j=0; j<vec.size(); j++){
                if((i%(2*vec[j]))>=0 && (i%(2*vec[j]))<vec[j]-5)  ++check;
            }
            if(check == vec.size()) {
                ans=i;
                break;
            }
        }
        if(ans!=-1)
            cout << setw(2) << setfill('0') << ans/3600 <<":"<< setw(2)<< setfill('0')<< (ans%3600)/60
                 << ":"<< setw(2)<< setfill('0')<< (ans%60) <<endl;
        else
            cout << "Signals fail to synchronise in 5 hours\n";

    vec.clear();
    }


    return 0;
}

#endif