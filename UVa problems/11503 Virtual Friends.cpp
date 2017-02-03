//11503 Virtual Friends
//#define Q11503
#ifdef Q11503

#include <bits/stdc++.h>
using namespace std;
typedef vector<int>vi;

vi members,rnk,p;
void buildUF(int n){
    p.clear();
    p.assign(n+1,0);
    rnk.clear();
    for (int i = 0; i <= n; i++) {
        p[i]=i;
        //members.push_back(1);
        rnk.push_back(1);
    }

}
int findSet(int i){
    return (p[i]==i) ? i : (p[i]=findSet(p[i]));
}
int isSameSet(int i, int j){
    return (findSet(i)==findSet(j));
}
int unionSet(int i,  int j){

    int x=findSet(i);
    int y=findSet(j);

    if(!isSameSet(i,j)){


        if(rnk[x] > rnk[y]){
            //members[x]+=members[y];
            rnk[x]+=rnk[y];
            p[y]=x;
            return rnk[x];
        }
        else {
            p[x]=y;
            rnk[y]+=rnk[x];
            //if(rnk[x] == rnk[y]) rnk[y]++;
            return rnk[y];

        }
    }
    return rnk[x];
}

int main(){

    ios::sync_with_stdio(0);
    int tc;cin >> tc;
    int fship;
    string name1,name2;
    while(tc--){
        cin >> fship;
        buildUF(fship);
        map<string,int>num;
        int count=0;
       for(int j=0; j<fship; j++){
            cin>>name1>>name2;
            if(!num.count(name1)) {
                num[name1] = count++;
            }
            if(!num.count(name2)) {
                num[name2] = count++;
            }
            cout << unionSet(num[name1],num[name2])<<endl;
        }
    }

    return 0;
}

#endif