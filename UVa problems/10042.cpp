//#define Q10042
#ifdef Q10042

#include "bits/stdc++.h"
using namespace std;
typedef  long long int ll;
typedef vector<int> vi;
ll sieve_size;
bitset<1000010> bs; // 10^7 should be enough for most cases
vi primes;

// create list of primes in [0..upperbound]
void sieve(ll upperbound) {
    sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i <= sieve_size; i++)
        if (bs[i]) {
            // cross out multiples of i starting from i * i!
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
    int t; cin >> t;
    int n;
    sieve(1000000);
    while(t--){
        cin >> n;
       while(n++) {
            vi ans = primeFactors(n);
           if(ans.size() == 1 && ans[0] == n) continue;
            int sum = 0, temp = n;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            int facts = 0;
            for (int i = 0; i < ans.size(); ++i) {
                int num = ans[i], s = 0;
                while (num){
                    s += num % 10;
                    num /= 10;
                }
                facts += s;
            }
            if (sum == facts) {
                cout << n << endl;
                break;
            }
        }
    }
    return 0;
}

#endif