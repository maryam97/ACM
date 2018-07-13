//#define Q12210
#ifdef Q12210

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int B,S,tc=0;
    while(cin >> B >> S && (B||S)){
        cout << "Case "<< ++tc << ": ";
        vector<int>bachelor(B);
        vector<int>spins(S);
        for (int i = 0; i < B; ++i) {
            cin >> bachelor[i];
        }
        for (int j = 0; j < S; ++j) {
            cin >> spins[j];
        }
        if(B<=S) cout << "0\n";
        else{
        sort(bachelor.begin(),bachelor.end());
            cout << B-S <<" "<< bachelor[0] << endl;
        }

    }
    return 0;
}

#endif