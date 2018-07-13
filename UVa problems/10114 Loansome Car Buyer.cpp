//10114 Loansome Car Buyer
//#define Q10114
#ifdef Q10114

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int month,dep,num;
    double down,loan,perc;
    double money=0;
    while(cin >> month >> down >> loan >> dep ){
        if(month<0)break;
        money=loan+down;
        map<int,float>deps;
        while(dep--){
            cin >> num >> perc;
            deps[num]=perc;
            for(int i=0;i<num;i++){
                if(deps[i]==0){
                    deps[i]=deps[i-1];
                }
            }
        }
        for(int i=num+1;i<month;i++) deps[i]=deps[num];
        int ans=0;
        down = loan/month;
        money*=(1-deps[0]);
        int i=0;
        while(loan>money){
            i++;
            loan-=down;
            money*=(1-deps[i]);
        }
        ans = i;
        if(ans > 1 || ans==0) cout << ans << " months\n";
        else cout << ans << " month\n";
    }


    return 0;
}

#endif