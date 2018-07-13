//#define Q11517
#ifdef Q11517
using namespace std;

#include <bits/stdc++.h>
typedef vector<int> vi;
typedef vector<vi> vvi;
#define inf 100000000
vi memo;
vi sum;
vi coins;
int type,price,cur;
/*int change(int val){
    //if(val != price)
        //cur = val;

    if(val==0) return 0;
    if(val<0)  return inf;
    if(memo[val]<inf) return memo[val];
    memo[val]=0;
    //sum[val]=0;
    for (int i = 0; i <coins.size() ; ++i) {

        memo[val] = min(memo[val],change(val - coins[i]))+1;
        if(val >= coins[i])
            sum[val] += coins[i] ;
    }
    cout << "val: "<< val <<" Sum: "<< sum[val] << endl;
    return memo[val];
}*/
int x;
int change(int val){
    if (val==0) return 0;
    memo[0]=0;
    for (int i = 0; i < coins.size(); ++i) {
        for (int j = 20000 - coins[i]; j >= 0; j--) {
            if(memo[j]<inf){
                memo[j+coins[i]]=min(memo[j+coins[i]],memo[j]+1);
                if(j+coins[i]>=val ) x=min(x,j+coins[i]);
            }
        }
    }
    return x;
}

int main(){
    ios::sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--){
        cin >> price >> type;
        coins.clear();
        coins.resize(type+1,0);
        memo.clear();
        memo.resize(20001, inf);
        x=inf;
        for (int i = 0; i < type; ++i) {
            cin >> coins[i];
        }
        int ans = change(price);
        cout << ans <<" " <<memo[ans] <<endl;
    }
    return 0;
}


#endif