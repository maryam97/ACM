//
// Created by maryam on 8/27/17.
//
//#define Q10680
#ifdef Q10680

#include "bits/stdc++.h"
using namespace std;


typedef long long int ll;
typedef unsigned long long int ull;
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
//ull lcm = 1;
void primeFactors(ll n, ull &lcm ) {
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= n) {
        //int x = 0;
        while (n % PF == 0) {
            n /= PF;
            factors.push_back(PF);
            //x++;
        }
       // vec[PF] = max(vec[PF], x);
        PF = primes[++PF_idx];
    }
    if (n != 1) { factors.push_back(n);    } // special case if n is a prime

    if(factors[0] == factors.back()) lcm *= factors.back();
    lcm %= inf;
    ll p = 10;
    while (lcm % p == 0) lcm /= p;
   // return lcm;
}


int main(){
    ios::sync_with_stdio(0);
    int n;
    sieve(2000000);
    vector<char>ans;
    ull lcm = 1;
    for (int i = 2; i <= 1e6 ; ++i) {
        primeFactors(i, lcm);
        //int a = lcm%10;
        ans.push_back((lcm%10) + '0');
    }
    while(cin >> n && n){
        if (n == 1) cout << 1 << endl;
        else cout << ans[n-2] << endl;
    }

    return 0;
}

#endif
