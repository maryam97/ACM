//#define Q443
#ifdef Q443

#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
#define mx 2000000001


int main(){
    ios::sync_with_stdio(0);
    int n;
    //cout << mx << endl;
    vector<ll> ans;
    for (int i = 0; i <= 31; ++i) {
        for (int j = 0; j <= 19; ++j) { if(pow(2.0,i) * pow(3.0,j) > mx) break;
            for (int k = 0; k <= 14; ++k) { if(pow(2.0,i) * pow(3.0,j) * pow(5.0,k) > mx) break;
                for (int l = 0; l <= 12; ++l) { if(pow(2.0,i) * pow(3.0,j) * pow(5.0,k) * pow(7.0,l) > mx) break;
                    ans.push_back(pow(2.0,i) * pow(3.0,j) * pow(5.0,k) * pow(7.0,l));
                }
            }
        }
    }
    //cerr << ans.size() << endl;
    sort(ans.begin(), ans.end());
    while(cin >> n && n){
        int temp = n/10;
        int a = n % 10, b = temp % 10;

        cout << "The " << n ;
        if(a == 1 && b!=1) cout << "st"; else if(a == 2 && b!=1) cout << "nd"; else if(a == 3 && b!=1) cout << "rd"; else cout << "th";
        cout << " humble number is "<< ans[n-1] <<"."<<endl;
    }

    return 0;
}

#endif