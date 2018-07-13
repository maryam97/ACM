//#define Q10203
#ifdef  Q10203

#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vector<ii>> vvii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef unsigned long long llu;
#define inf 1000000000
vvii adjlist;
list<int>cyc;

/*void eulertour(list<int>::iterator i, int u){
    for (int j = 0; j < adjlist[u].size(); ++j) {
        ii &v = adjlist[u][j];
        if(!v.second) v.second = 0;
        for (int k = 0; k < adjlist[v.first].size(); ++k) {
            ii & uu = adjlist[v.first][k];
            if(!uu.second && uu.first == u){ uu.second = 0; break;}
        }
        eulertour(cyc.insert(i, u),v.first);
    }
}*/

int main(){
    ios::sync_with_stdio(0);
    int tc;cin >> tc;
    cin.ignore();
    while(tc--){
        adjlist.clear();
        adjlist.resize(102);
        int xs,ys,x,y,xx,yy;
        cin >> xs >> ys;cin.ignore();
        double sum = 0;
        string str;
        while(getline(cin , str) && !str.empty()){
            stringstream ss(str);
            ss >> x >> y >> xx >> yy;
            sum += 2*hypot(xx-x,yy-y);
        }
        sum = sum / 20000;
        int h = floor(sum);
        sum -= h;
        sum *= 60;
        int min = floor(sum);

        if(sum - min > 0.5) min++;
        if(min >= 60) min-=60, h++;
        cout << h << ":" << setw(2) << setfill('0') << min << endl;
        if(tc) cout << endl;
    }

    return 0;
}


#endif