//624 CD
//#define Q624
#ifdef Q624

#include <bits/stdc++.h>
using namespace std;

int sum,Size,n;
int indx;
vector<int>tmp(20),ans(20),num(20);

void answer(int i,int j,int cur){
    if(cur > sum){
        sum = cur;
        indx=i;
        for (int k = 0; k <= i; ++k) {
            ans[k] = tmp[k];
        }
    }
    for (int l = j+1; l < n ; ++l) {
        if(cur+num[l] <= Size){
            tmp[i+1]=num[l];
            answer(i+1,l,num[l]+cur);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);

    while(cin >> Size){
        sum=indx=0;
        cin >>n;
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        for (int j = 0; j < n; ++j) {
            tmp[0]=num[j];
            answer(0,j,num[j]);
        }
        for (int k = 0; k < indx+1; ++k) {
            cout << ans[k] << " ";
        }
        cout << "sum:"<<sum<<endl;
    }

    return 0;
}



#endif