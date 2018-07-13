//#define Q827
#ifdef Q827

#include <bits/stdc++.h>
using namespace std;
vector<char>letter;
map<pair<char,char>,int>mp;
vector<string>ans;
void backtrack(string s,int bitmask){
    if(s.size()==letter.size()) {
        ans.push_back(s);
        return;
    }
    for (int i = 0; i < letter.size(); ++i) {
        if(bitmask & (1 << i)) continue;

        bool found = false;
        for (int j = 0; j < s.size(); ++j) {
            if(mp[make_pair(letter[i],s[j])]!=0){
                found = true;
                break;
            }
        }
        if(found) continue;
        string str = s + letter[i];
        backtrack(str, bitmask|(1<<i));
    }
}

int main(){
    ios::sync_with_stdio(0);
    int tc;cin >> tc;
    cin.ignore();
    string inp;

    while(tc--){
        cin.ignore();
        mp.clear();
        getline(cin,inp);
        letter.clear();
        ans.clear();
        for (int i = 0; i < inp.size(); ++i) {
            if(inp[i]!=' ') {
                letter.push_back(inp[i]);

            }
        }
        getline(cin,inp);
        for (int j = 0; j < inp.size(); ++j) {
            if(inp[j]=='<')
                mp[make_pair(inp[j-1],inp[j+1])]++;
        }
        sort(letter.begin(),letter.end());
        backtrack("",0);
        if(!ans.size()) cout << "NO\n";
        else{
            for (int i = 0; i < ans.size(); ++i) {
                cout << ans[i][0];
                for (int j = 1; j < ans[i].size(); ++j) {
                    cout <<" " << ans[i][j];
                }cout << endl;
            }
        }

        if(tc) cout << endl;
    }
    return 0;
}

#endif