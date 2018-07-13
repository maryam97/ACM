//#define Q11389
#ifdef Q11389

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n,d,r;
    while(cin >> n >> d >> r && (n||d||r)){
        vector<int>morning(n),evening(n);
        for (int i = 0; i < n; ++i) {
            cin >>morning[i];
        }
        for (int j = 0; j < n; ++j) {
            cin >> evening[j];
        }
        sort(morning.begin(),morning.end());
        sort(evening.rbegin(),evening.rend());
        int overtime=0;

        for (int k = 0; k < n; ++k) {
            if((morning[k]+evening[k]) >= d)
                overtime+=((morning[k]+evening[k]-d)*r);
        }
        cout << overtime << endl;
    }



    return 0;
}

#endif