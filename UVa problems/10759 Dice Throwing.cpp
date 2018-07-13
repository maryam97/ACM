//
// Created by maryam on 9/27/17.
//

//#define Q10759
#ifdef Q10759

#include "bits/stdc++.h"
using namespace std;
#include <bits/stdc++.h>

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
typedef unsigned long long ull;
#define inf 1e9
#define sup 1e-9
int n, x;
vector <vector<ll>> memo(25,vll(160,-1));
ll sol(int dice_left, int score){
    if(dice_left == 0){
        if(score >= x) return 1;
        else return 0;
    }
    if(memo[dice_left][score] != -1) return memo[dice_left][score];
    int ans = 0;
    for (int i = 1; i <= 6 ; ++i) {
        ans += sol(dice_left - 1, score + i);
    }
    return memo[dice_left][score] = ans;
}

ll gcd(ll a, ll b){
    return b == 0 ? a : (gcd(b, a % b));
}
int main(){
    ios::sync_with_stdio(0);

    while(cin >> n >> x && (n||x)){
        ll s = sol(n, 0);
        ll m = (ll)pow(6.0, n);
        ll g = gcd(s,m);
        cout << s << " " << m << " " << g << endl;
        if(!s) cout << 0 << endl;
        else
            cout << s / g << "/" << m / g << endl;
    }

    return 0;
}

#endif