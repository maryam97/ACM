//10920 Spiral Tap
//#define Q10902
#ifdef Q10902

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(0);

    ll s,p;
    while(cin>>s>>p && (s || p)){
        ll b,a;
        ll n=sqrt(p);
        //cout<<"n   "<<n<<endl;
        if(n%2) {
            b=n;
            a=n+2;
        }
        else{
            b = n - 1;
            a = n + 1;

        }
        //cout<<"b   "<<b<<endl;
        int diff=s-b;
        diff/=2;
        diff=s-diff;
        int x=diff,y=diff;
        ll i=b*b;
        bool check=false;
        if(p==i) {
            check=true;
        }
        else{
            i++;
            y++;
        }
        if(!check) {
            for (int j = 0; j < a - 2; j++) {
                if (p == i) {
                    check = true;
                    break;
                }
                x--;
                i++;
            }
        }
        if(!check){
            for(int j=0;j<a-1;j++){
                if(p==i){
                    check=true;
                    break;
                }
                y--;
                i++;
            }
        }
        if(!check){
            for(int j=0;j<a-1;j++){
                if(p==i){
                    check=true;
                    break;
                }
                x++;
                i++;
            }
        }
        if(!check){
            for(int j=0;j<a-1;j++){
                if(p==i){
                    check=true;
                    break;
                }
                y++;
                i++;
            }
        }
        cout<<"Line = "<<y<<", column = "<<x<<".\n";
    }

    return 0;
}

#endif
