//
// Created by maryam on 8/28/17.
//
//#define Q10699
#ifdef Q10699

#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
#define inf 1000000000
#define MAX_N 1000000
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
vi numDiffPF(MAX_N, 0);
void mod_sieve() {
    for (int i = 2; i < MAX_N; i++)
        if (numDiffPF[i] == 0) // i is a prime number
            for (int j = i; j < MAX_N; j += i)
                numDiffPF[j]++;
}

int main(){
    ios::sync_with_stdio(0);
    int n;
    sieve(1000000);
    mod_sieve();
    while(cin >> n && n){
        cout << n << " : " << numDiffPF[n] << endl;
    }
    return 0;
}

#endif
