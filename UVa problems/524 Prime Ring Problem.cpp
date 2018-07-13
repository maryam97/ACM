//524 Prime Ring Problem
#define Q524
#ifdef Q524

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int n,sum;
int num[16];
vi ans,temp,mark;
set<vi> answer;


int isPrime(int a){
    if(a%2==0) return false;
    for (int i = 3; i < a ; ++i) {
        if(!(a % i)) return false;
    }
    return true;
}

void solve(int i, int cur){
    if(isPrime(sum)){
        for (int j = 0; j <= i; ++j) {
            ans[j] = temp[j];
        }
    }
    for (int k = 0; k < n; ++k) {
        if(!mark[k]) {
            if (isPrime(cur + num[k])) {
                temp[i + 1] = num[k];
                sum = cur + num[k];
                mark[k] = 1;
                solve(i + 1, num[k]);
                mark[k] = 0;
            }
        }
    }
    bool yes = true;
    for(int l=0; l<n; l++) {
        if (!mark[l]) {
            yes = false;
        }
    }
    if(yes && isPrime(ans[n-1]+1)) {
        answer.insert(ans);
    }
}

int main(){
    ios::sync_with_stdio(0);
    int Case=0;
    while(cin >> n){
        if(Case) cout << endl;
        answer.clear();
        temp.clear();
        temp.assign(n,0);
        memset(num,0,n);

        for (int i = 0; i < n; ++i) {
            num[i] = i+1;
        }
        temp[0]=1;
        ans.clear();
        ans.resize(n);
        mark.clear();
        mark.resize(n,0);
        /*for (int i = 0; i <= n; ++i) {
            mark[i]=0; //:|
        }*/
        mark[0]=1;
        sum=0;
        ans[0]=1;
        solve(0,1);
        cout << "Case " << ++Case << ":\n";
        if(n==1) cout << "1\n";
        else {
            set<vi>::iterator it;
            for (it = answer.begin(); it != answer.end(); it++) {
                for (int i = 0; i < (*it).size() - 1; ++i) {
                    cout << (*it)[i] << " ";
                }
                cout << (*it)[(*it).size() - 1] << endl;
            }
        }
        //cout << endl;

    }

    return 0;
}


#endif