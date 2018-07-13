#define Q10139
#ifdef Q10139

#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
ll sieve_size;
bitset<10000010> bs;
vi primes;
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
bool isPrime(ll n) {
    if (n <= sieve_size) return bs[n];
    for (int i = 0; i < primes.size(); i++)
        if (n % primes[i] == 0) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    int n,m;
    sieve(1000000);
    while(cin >> n >> m){
        vi fac = primeFactors(m);
        int sz = fac.size(), num = 0;
        //cout << sz << endl;
        map<int,int> mp;
        if(m > n) cout << m << " does not divide "<< n <<"!\n";
        else {
            for (int i = n; i >= 2; i--) {
                int tmp = i;
                //if(!isPrime(tmp)) {
                    for (int j = 0; j < sz && num < sz; ++j) {
                        if ((tmp % fac[j] == 0) && (mp.find(j) == mp.end()))
                            num++, mp[j] = 1, tmp /= fac[j];
                        if (tmp == 1) break;
                    }
                    if (num == sz) break;
                //}
            }
            if (num < sz) cout << m << " does not divide " << n << "!\n";
            else cout << m << " divides " << n << "!\n";
        }
    }


    return 0;
}

#endif