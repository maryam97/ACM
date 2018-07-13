//#define Q10137
#ifdef Q10137

#include "bits/stdc++.h"
#include <math.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n){
        vector<double> vec(n);
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
            sum += vec[i];

        }
        double med = sum/n;
        double n=0 , p=0;
        for (int j = 0; j < vec.size(); ++j) {
            int diff = (med - vec[j])*100;
            if(diff < 0) n += diff;
            else p += diff;
        }
        cout << "$" << fixed << setprecision(2) << ((fabs(n) > p) ? fabs(n) : p)/100 << endl;
    }
    return 0;
}

#endif