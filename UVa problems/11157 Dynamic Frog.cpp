// :|||||||||||||||||||||
// #define Q11157
#ifdef Q11157

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    int T;cin >> T;
    int N;
    ll D,n,ans;
    char s,c;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> D;
        cout << "Case " << t <<": ";
        vector<ll>dis;
        ans=0;
        map<ll,char>siz;
        int big = 0;
        for (int k = 0; k < N ; ++k) {
            cin >> s >> c >> n;

            if (dis.size() == 0) dis.push_back(n);
            else dis.push_back(n-dis[dis.size()-1]);
            siz[k] = s;
            if(s=='B') ++big;
        }
        dis.push_back(D-n);
        siz[N] = 'E';
        int j=0,i=0,I=0;
        if(!big) {
            if(dis.size()==2){
                ans = dis[0]+dis[1];
            }
            else {
                for (; i + 2 <= dis.size(); i += 2) {
                    ans = max(ans, (dis[i] + dis[i + 1]));
                }
                i=1;
                for (; i + 2 <= dis.size(); i += 2) {
                    ans = max(ans, (dis[i] + dis[i + 1]));
                }
            }
        }
        else {
            while (j < dis.size()) {
                //if(big == 1 && siz[dis[0]]=='B') j=dis.size();

                while(siz[j] == 'B'){
                    ans = max(ans,dis[j]);
                    j++;i++;I++;
                }
                if(j!=N && siz[j] != 'B')
                    while (siz[j] != 'B' && j<=N-1)
                        ++j;
                for (; i + 2 <= j; i += 2) {
                    ans = max(ans, (dis[i] + dis[i + 1]));
                }
                I++;
                for (; I + 2 <= j; I += 2) {
                    ans = max(ans, (dis[I] + dis[I + 1]));
                }
                i = j;I = j;
                j++;
            }
            I=j;
            for (; j + 2 <= N; j += 2) {
                ans = max(ans, (dis[j] + dis[j + 1]));
            }
            I++;
            for (; I + 2 <= N; I += 2) {
                ans = max(ans, (dis[I] + dis[I + 1]));
            }
        }
        if(siz[N-1]=='S')
            ans = max(ans, max(dis[0], dis[N]+dis[N-1]));
        else
            ans = max(ans, max(dis[0], dis[N]));

        cout << ans << endl;

    }

    return 0;
}

#endif