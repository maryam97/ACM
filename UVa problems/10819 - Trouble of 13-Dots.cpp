#define Q10819
#ifdef Q10819

#include <bits/stdc++.h>
using namespace std;
int MW,n;
vector<int>W,V;
vector<vector<int>> memo;
int knapsack(int id, int w){
    if(id==n){
        int a = MW + 200 - w;
        if(a > MW && a <= 2000) return INT32_MIN;
        return 0;
    }
    if(memo[id][w] !=-1) return memo[id][w];
    if(W[id] <= w) return memo[id][w] = max(knapsack(id+1,w),V[id]+knapsack(id+1,w-W[id]));
    return memo[id][w] = knapsack(id+1,w);
}
int main(){
    ios::sync_with_stdio(0);
    while(cin >> MW >> n){
        W.clear();V.clear();
        W.resize(MW+1);V.resize(n+2);
        memo.clear();memo.resize(n+2,vector<int>(MW+210,-1));
        for (int i = 0; i < n; ++i) {
            cin >> W[i] >> V[i];
        }
        cout << knapsack(0,MW+200) << endl;
    }

    return 0;
}

#endif