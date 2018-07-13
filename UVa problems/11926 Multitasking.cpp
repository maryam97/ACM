//11926 Multitasking
//#define Q11926
#ifdef Q11926

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n,m,start,end,rep;
    while(cin >> n >> m && (n || m)){
        bitset<1000010>bs;
        bool check=false;
        while(n--){
            cin >> start >> end;
            for(int i=start+1; i<=end ; i++){
                    if(bs[i]==1){
                        check=true;
                        break;
                    }
                bs.set(i);
            }
        }
        while(m--) {
            cin >> start >> end >> rep;
            while (start < 1000000) {
                for (int i = start+1; i <= end ; i++) {
                    if (bs[i] == 1) {
                        check = true;
                        break;
                    }
                    bs.set(i);

                }
                start += rep;
                end += rep;
                if (end > 1000000) end = 1000000;
            }
        }
        if(!check) cout << "NO CONFLICT\n";
        else cout << "CONFLICT\n";
    }

    return 0;
}

#endif