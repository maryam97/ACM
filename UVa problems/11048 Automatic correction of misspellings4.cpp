//
// Created by maryam on 10/9/17.
//
#define Q11048
#ifdef Q11048

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
typedef vector<vector<pair<string,int>>> vvsi;
typedef pair<string,int> psi;
#define inf 1e9
#define sup 1e-9


bool wrong(string m, string s){
  //bool wr = false;
    int diff = 0;
  for (size_t i = 0; i < m.size(); i++) {
      if(m[i] != s[i]){
        diff++;
      }

  }
  return (diff == 1);
}
int miss(string m, string s, int id){
    if(!id){
      int diff = 0;
      for (int i = 0, j = 0; i < s.size() && diff < 2; i++, j++) {
        if(s[i] != m[j]){
          diff++;
          i--;
        }
      }
      if(diff < 2) return id;
    }
    else{
      int diff = 0;
      for (int i = 0, j = 0; j < m.size() && diff < 2; i++, j++) {
        if(s[i] != m[j]){
          diff++;
          j--;
        }
      }
      if(diff < 2) return id;
    }
    return -1;
}
bool adj(string m, string s){
    for (size_t i = 0; i < m.size()-1; i++) {
      string tmp = m;
      for (size_t j = i + 1; j < m.size(); j++) {
          char a = tmp[i];
        tmp[i] = tmp[j];
          tmp[j] = a;
        if(tmp == s) return true;
      }
    }
    return false;
}

int main(){
  ios::sync_with_stdio(0);
    int n, m;
    string str;
    cin >> n;
    vvsi dict(10001);
    vi vis(10001,0);
    for(int i = 1; i <= n; i++){
        cin >> str;
        dict[(int)str.size()].push_back(psi(str,i));
        vis[(int)str.size()] = 1;
    }
    cin >> m;
    while(m--){
        cin >> str;
        string ans = "#";
        map <string,int> indx;
        bool correct = false, wr = false, mis = false, aj = false;
        if(vis[(int)str.size()]){
            for (size_t i = 0; i < dict[str.size()].size(); i++) {
                string s = dict[str.size()][i].first;
                if (s == str) {
                    correct = true;
                    break;
                }
            }
        }
        if(vis[(int)str.size()]){
        for (int j = 0; j < dict[str.size()].size(); j++) {
          string ss = dict[str.size()][j].first;
            if(wrong(str, ss)) {
                wr = true;
                if(ans != "#"){
                    if(indx[ans] > dict[str.size()][j].second)
                        ans = ss, indx[ans] = dict[str.size()][j].second;
                }
                else {
                    ans = ss;
                    indx[ans] = dict[str.size()][j].second;
                }
                break;
            }
            if(adj(str, ss)) {
                aj = true;
                if(ans != "#"){
                    if(indx[ans] > dict[str.size()][j].second)
                        ans = ss, indx[ans] = dict[str.size()][j].second;
                }
                else {
                    ans = ss;
                    indx[ans] = dict[str.size()][j].second;
                }
                break;
            }
        }
      }

        //if(!correct && !wr && !aj){
          int m = -2;
            if(vis[(int)str.size() - 1]) {
                for (size_t i = 0; i < dict[str.size() - 1].size(); i++) {
                    string s = dict[str.size() - 1][i].first;
                    m = miss(str, s, 0);
                    if (!m) {
                        mis = true;
                        if(ans != "#"){
                            if(indx[ans] > dict[str.size()-1][i].second)
                                ans = s, indx[ans] = dict[str.size()-1][i].second;
                        }
                        else {
                            ans = s;
                            indx[ans] = dict[str.size()-1][i].second;
                        }
                    }
                }
            }
        if(m != 0 && vis[(int)str.size() + 1]){
          for (size_t i = 0; i < dict[str.size() + 1].size(); i++) {
            string s = dict[str.size() + 1][i].first;
            if(miss(str, s, 1) == 1) {
                mis = true;
                if(ans != "#"){
                    if(indx[ans] > dict[str.size()+1][i].second)
                        ans = s, indx[ans] = dict[str.size()+1][i].second;
                }
                else {
                    ans = s;
                    indx[ans] = dict[str.size()+1][i].second;
                }
            }
          }
        }
      //}
        if(correct) cout << str << " is correct" << endl;
        else if(wr || mis || aj)
          cout << str << " is a misspelling of " << ans << endl;
        else cout << str << " is unknown" << endl;

    }

    return 0;
}

#endif
