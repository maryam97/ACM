//#define Q10940
#ifdef Q10940

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n;
    while(cin >> n && n ){
        list<int>q;
        for (int i = 2; i <= n; i+=2) {
            q.push_back(i);
        }
       //cout << q.front() << "   " << q.back() << endl;
        while(q.size() > 2) {
            if (n % 2) {
                q.pop_front();
                if (q.size() == 2) break;
                int a = q.front();
                q.pop_front();
                q.push_back(a);
            }
            else {
                int a = q.front();
                q.pop_front();
                q.push_back(a);
                if (q.size() == 2) break;
                q.pop_front();
            }
        }
        cout << q.front() << endl;
    }

    return 0;
}

#endif