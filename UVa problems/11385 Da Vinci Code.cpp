//
// Created by maryam on 10/4/17.
//
//#define Q11385
#ifdef Q11385
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
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
typedef queue<ii> qii;
typedef pair<int , double> id;
typedef vector<id> vid;
typedef vector<vid> vvid;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef vector<vs> vvs;
#define inf 1e9
#define sup 1e-9
vll fibo(102);
map<ll,int> ord;
void fib(){
    fibo[1] = 1, fibo[2] = 2;
    ord[1] = 1, ord[2] = 2;
    for (int i = 3; i <= 101; ++i) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        ord[fibo[i]] = i;
    }
}
int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    fib();
    while(tc--) {
        int n, num;
        vi f;
        cin >> n;
        int mx = -1;
        map<int,int> vis;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            f.push_back(num);
            mx = max(mx, num);
            vis[ord[num]] = 1;
        }

        string line, str = "", ans = "";
        cin.ignore(100 , '\n');
        getline(cin, line);
        int sz = 0;
        for (int j = 0; j <line.size() ; ++j) {
            if(isalpha(line[j]) && isupper(line[j])){
                str.push_back(line[j]), sz++;
            }
        }
        ans.resize(ord[mx],' ');
        int x = 0;
        for (int i = 0; i < f.size(); ++i) {
            ans[ord[f[i]]-1] = str[i];
        }
        cout << ans << endl;

    }
    return 0;
}

#endif
