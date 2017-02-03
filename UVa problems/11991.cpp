//11991 Easy Problem from Rujia Liu?
//#define Q11991
#ifdef Q11991

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        int k,num;
        map<int,vector<int>> index;
        for(int i=1; i<=n; i++) {
            cin >> num;
            index[num].push_back(i);
        }

        while (m --){
            cin >> k >> num;
            if(index.count(num) == 0) cout << 0 << endl;
            if ( index[num].size() >= k){
                cout << index[num][k-1]<<endl;
            }
            else cout << 0 << endl;
        }
    }
}


#endif