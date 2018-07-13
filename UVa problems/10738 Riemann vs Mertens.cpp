//
// Created by maryam on 8/28/17.
//
//#define Q10738
#ifdef Q10738
#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
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

int numDiffPF(ll n) {
    ll PF_idx = 0, PF = primes[PF_idx]; int ans = 0;
    while (PF * PF <= n) {
        int power = 0;
        while (n % PF == 0) {
            n /= PF;
            power++;
        }
        if (power)
            ans++;
        if(power > 1) {
            ans = -10;
            break;
        }
        PF = primes[++PF_idx];
    }
    if (n != 1) ans++;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    int n;
    sieve(1000000);
    vi mu(1000001,-10);
    vi M(1000001,-10);
    mu[1] = M[1] = 1;
    while(cin >> n && n) {
        if (mu[n] != -10) cout << setw(8) << n << setw(8) << mu[n] << setw(8) << M[n] << endl;
        else {
            for (int i = 2; i <= n; ++i) {
                if(mu[n] == -10) {
                    mu[i] = numDiffPF(i);
                    if (mu[i] < 0) mu[i] = 0;
                    else if (mu[i] % 2 == 0) mu[i] = 1;
                    else if (mu[i] % 2) mu[i] = -1;
                }
                M[i] = mu[i] + M[i - 1];
            }
            cout << setw(8) << n << setw(8) << mu[n] << setw(8) << M[n] << endl;
        }
    }

    return 0;
}


#endif
