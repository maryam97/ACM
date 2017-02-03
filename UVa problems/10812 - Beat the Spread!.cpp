//10812 - Beat the Spread!
//#define Q10812
#ifdef Q10812

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int sum,diff,a,b,tc; cin >> tc;
    while(tc --){
        cin >> sum >> diff;
        if((sum + diff)%2 ==0) {
            a = (sum + diff) / 2;
            b = sum - a;
            if(a>=0 && b>=0)
                cout << a << " " << b<<endl;
            else cout << "impossible\n";
        }
        else cout << "impossible\n";

    }




    return 0;
}

#endif