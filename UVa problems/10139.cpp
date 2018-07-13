//#define Q10139
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

bool primeFactors(int nn,ll n) {
    map<int,int> num;
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= n) {
        while (n % PF == 0) {
            n /= PF;
            factors.push_back(PF);
            num[PF]++;
        }
        PF = primes[++PF_idx];
    }
    if (n != 1) factors.push_back(n), num[n]++; // special case if n is a prime

    bool div = true;
    for (auto i : num) {
        int tmp = nn; ll sum = 0;
        while (tmp) {
            sum += (tmp / i.first);
            tmp /= i.first;
        }
        if (sum < i.second) {
            div = false;
            break;
        }
    }
    return div;
}


int main(){
    ios::sync_with_stdio(0);
    int n,m;
    sieve(10000000);
    while(cin >> n >> m) {
        bool ans = primeFactors(n, m);
        if (ans) cout << m << " divides " << n << "!\n";
        else cout << m << " does not divide " << n << "!\n";

    }


    return 0;
}

#endif