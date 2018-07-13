//#define Q10616
#ifdef Q10616

#include <bits/stdc++.h>
#define inf 100000010
using namespace std;

int N,Q,num,M,D;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
vvvi arr;
vector<int>nums;
int ans(int i,long long sum,int m){
    int mod = ((sum%D)+D)%D;
    if(m==M){
        if(mod==0) return 1;
        else return 0;
    }
    if(arr[i][mod][m] != -inf) return arr[i][mod][m];
    arr[i][mod][m]=0;

    for(int j=i;j<nums.size();j++){
        arr[i][mod][m] += ans(j+1,sum+nums[j],m+1);
    }
    return arr[i][mod][m];


}

int main(){
    ios::sync_with_stdio(0);

    int count=0;
    while(cin >> N >> Q && (N||Q)){
        nums.clear();
        cout << "SET " << ++count <<":"<< endl;
        for (int j = 0; j < N; ++j) {
            cin >> num;
            nums.push_back(num);
        }
        for(int i=1;i<=Q;i++){
            cin >> D >> M;
            arr.clear();
            arr.assign(N+2,vvi(D+2,vi(M+2,-inf)));
            cout << "QUERY " << i << ": ";
            cout << ans(0,0,0) << endl;
        }

    }
    return 0;
}
#endif