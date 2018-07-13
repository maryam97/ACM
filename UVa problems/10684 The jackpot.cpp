//#define Q10684
#ifdef Q10684

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int N,num;
    while(cin >> N && N){
        int sum=0,ans=-1;
        for (int i = 0; i < N; ++i) {
            cin >> num;
            sum += num;
            if(sum < 0) sum=0;
            ans = max(ans,sum);
        }
        if(ans) cout << "The maximum winning streak is "<< ans <<".\n";
        else cout << "Losing streak.\n";
    }

    return 0;
}

#endif