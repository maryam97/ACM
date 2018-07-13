//
// Created by maryam on 8/28/17.
//
//#define Q10179
#ifdef Q10179

#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
#define inf 1000000000
ll sieve_size;
bitset<10000010> bs;
map <int,int> num;
vi primes;
vi vec;
void sieve(ll upperbound) {
    sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i < sieve_size; i++)
        if (bs[i]) {
            for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);

        }
}
ll EulerPhi(ll n) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = n;
    while (PF * PF <= n) {
        if (n % PF == 0) ans -= ans / PF;
        while (n % PF == 0) n /= PF;
        PF = primes[++PF_idx];
    }
    if (n != 1) ans -= ans / n;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    sieve(10000000);
    int n;
    while(cin >> n && n){
        cout << EulerPhi(n) << endl;
    }

    return 0;
}

#endif
