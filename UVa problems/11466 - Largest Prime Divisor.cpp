/*#define Q11466
#ifdef Q11466

#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
#define mx 1000000000
ll sieve_size;
bitset<10000010> bs;
vi primes;
map<int,int> num;
void sieve(ll upperbound) {
    sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = mx; i >= 2; i--)
        if (bs[i]) {
            for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);

        }
}

vi primeFactors(ll n) {
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= n) {
        while (n % PF == 0) {
            n /= PF;
            factors.push_back(PF);
        }
        PF = primes[++PF_idx];
    }
    if (n != 1) factors.push_back(n); // special case if n is a prime
    return factors;
}

int main(){
    ios::sync_with_stdio(0);
    ll num;
    sieve(2*1e7 + 100);
    while(cin >> num && num){
        vi facts = primeFactors(abs(num));
        int ans = facts.size() >= 2 ? facts.back() : -1;
        cout << ans << endl;
    }

    return 0;
}
#endif*/