//
// Created by maryam on 1/23/17.
//

//#define p11849
#ifdef p11849

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, ans;
    set<int> s;
    while (cin >> n >> m && ( n || m)) {
        ans = 0;
        while(n--){
            int x; cin >> x; s.insert(x);
        }
        while (m--) {
            int x; cin >> x; if (s.count(x) == 1) ans++;
        }
        cerr << "---------------------";
        cout << ans << endl;
        s.clear();
    }
    return 0;
}

#endif
