//
// Created by maryam on 10/4/17.
//
//#define Q554
#ifdef Q554

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

int main(){
    ios::sync_with_stdio(0);
    string str;
    vs dict;
    map<string,int> mp;
    vc character;
    character.push_back(' ');
    for (int i = 65; i <91 ; ++i) {
        character.push_back(char(i));
    }
    while(cin >> str && str[0] != '#'){
        dict.push_back(str);
        mp[str] = 1;
    }
    cin.ignore();
    string uncypher, cypher = "";
    getline(cin, uncypher);
    bool fnd = false;
    for (int k = 1; k <= 27; ++k) {
        cypher = "";
        for (int j = 0; j < uncypher.size(); ++j) {
            char a =  character[(uncypher[j] - 65 + k + 1) % 27];
            if(uncypher[j] == ' ')
                a = character[(k) % 27];
            cypher += a;
            if(mp.find(cypher) != mp.end()){
                fnd = true;
            }
        }
        if(fnd) {
            string word = "";
            vs ans;
            for (int i = 0; i < cypher.size(); ++i) {
                if(cypher[i] == ' '){
                    ans.push_back(word);
                    word = "";
                    continue;
                }

                word += cypher[i];
            }
            if(word != "") ans.push_back(word);
            /*int x = 0;
            for (int j = 0; j < ans.size(); ++j) {
                if((x + ans[j].size() + 1) > 60)
                {
                    cout << endl;
                    x = 0;
                }
                cout << ans[j];
                x += ans[j].size();
                if((x + ans[j+1].size() + 1) <= 60)
                    if(j != ans.size()-1) {x++; cout << " ";}
            }*/
            int sz = 0;
            for(auto &e : ans) {
                if(sz + e.size() > 60) cout << endl, sz = 0;
                if(sz) cout << " ", sz++;
                cout << e;
                sz += e.size();
            }
            cout << endl;
            break;
        }
    }

    return 0;
}

#endif
