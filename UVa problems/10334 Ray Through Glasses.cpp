//#define Q10334
#ifdef Q10334

#include "bits/stdc++.h"
using namespace std;
vector<int> fibo(1010);

void fib(){
    fibo[0] = fibo[1] = 1;
    for (int i = 2; i <= 1000; ++i) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}

int main(){
    ios::sync_with_stdio(0);
    int n;
    fib();
    while(cin >> n){
        cout << fibo[n-1] << endl;
    }

    return 0;
}

#endif