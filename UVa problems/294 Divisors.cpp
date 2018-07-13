//
// Created by maryam on 8/28/17.
//
//#define Q294
#ifdef Q294

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
ll numDiv(ll n) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
    while (PF * PF <= n) {
        ll power = 0;
        while (n % PF == 0) {
            n /= PF;
            power++;
        }
        ans *= power + 1;
        PF = primes[++PF_idx];
    }
    if (n != 1) ans *= 2; // last factor has pow = 1, we add 1 to it
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    int n;cin >> n;
    sieve(10000000);
    while(n--){
        int L,U,P = -1;
        ll D = -1;
        cin >> L >> U;
        for (int i = L; i <= U; ++i) {
            ll ans = numDiv(i);
            if(D < ans)
                P = i, D = ans;
        }
        cout << "Between "<< L << " and "<< U << ", "<< P <<" has a maximum of "<< D <<" divisors.\n";
    }

    return 0;
}

#endif
