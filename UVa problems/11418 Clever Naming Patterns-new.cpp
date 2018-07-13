//#define Q114180
#ifdef Q114180

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<viii> vviii;
typedef vector<vii> vvii;
typedef  stack<int> si;
typedef queue<int> qi;
typedef map<int,int> mii;
#define inf 1e9
#define sup 1e-9

using namespace std;

vi match, vis;
vvi adj;
int Aug(int l) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int j = 0; j < (int)adj[l].size(); j++) {
        int r = adj[l][j];
        if (match[r] == -1 || Aug(match[r])) {
            match[r] = l; return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        int num; cin >> num;
        int sz = num * 2 + 2;
        adj.assign(sz, vi());
        map<pair<int,char>,string> word;
        map<int,char> let;
        vvc vec(num + 1);
        for (int i = 1; i <= num; ++i) {
            int k; cin >> k;
            while(k--){
                string str; cin >> str;
                if(toupper(str[0]) - 64 > num) continue;
                transform(str.begin(), str.end(), str.begin(), ::tolower);
                word[make_pair(i,str[0])] = str;
                vec[i].push_back(str[0]);
                adj[i].push_back(str[0] - 96 + num);
                adj[str[0] - 96 + num].push_back(i);
                let[str[0] - 96 + num] = str[0];
            }
        }
        match.assign(sz, -1);
        for (int l = 1; l <= num; l++) {
            vis.assign(num + 1, 0);
            Aug(l);
        }

        set <string> ans;
        set <string>::iterator it;
        for (int i = num + 1; i <= num * 2; ++i) {
                for (auto &j : vec[match[i]])
                    if (let[i] == j)
                        ans.insert(word[make_pair(match[i],let[i])]);

        }
        cout << "Case #" << t << ":\n";
        for(it = ans.begin(); it!= ans.end(); it++){
            string s = *it;
            s[0] = (char)toupper(s[0]);
            cout << s << endl;
        }
    }
    return 0;
}

#endif