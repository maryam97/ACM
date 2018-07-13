//#define Q357
#ifdef Q357

#include <bits/stdc++.h>
using namespace std;
#define inf 100000
typedef vector<long long int> vl;
typedef vector<vl> vvl;
int coins[]={1,5,10,25,50};
//vvl memo;
long long memo[5][30001];

long long int ways(int type, int val){
    if(val==0) return 1;
    if(val<0 || type==5) return 0;
    if(memo[type][val]!=-1) return memo[type][val];
    return memo[type][val] = ways(type+1,val)+ways(type,val-coins[type]);
}
int main(){
    ios::sync_with_stdio(0);
    int num;
    memset(memo,-1,sizeof(memo));
    while(cin >> num ){

       long long int ans = ways(0,num);
        if (ans==1) cout << "There is only 1 way to produce "<<num<<" cents change.\n";
        else cout << "There are "<<ans<<" ways to produce "<<num<<" cents change.\n";
    }

    return 0;
}

#endif