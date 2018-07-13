//#define Q10235
#ifdef Q10235

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
    for (ll i = 2; i <= sieve_size; i++)
        if (bs[i]) {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

bool isPrime(ll n) {
    if (n <= sieve_size) return bs[n];
    for (int i = 0; i < primes.size(); i++)
        if (n % primes[i] == 0) return false;
    return true;
} // note: only work for n <= (last prime in vi "primes")^2

int stringtonum(string a){
    int sz = a.length();
    int num = 0;
    for (int i = 0; i < a.size(); ++i) {
        num += ((int(a[i])-48)*(pow(10.0,sz-i-1)));
    }
    return num;
}

int main(){
    ios::sync_with_stdio(0);
    string n;
    sieve(10000000);
    while(cin >> n){
        string m = n;
        bool ans = isPrime(stringtonum(n));
        //cerr << stringtonum(n) << endl;
        if(!ans) cout << m <<" is not prime.\n";
        else{
            reverse(n.begin(),n.end());
            bool rev = isPrime(stringtonum(n));
            if(rev && (n != m)) cout << m <<" is emirp.\n";
            else cout << m << " is prime.\n";
        }
    }

    return 0;
}

#endif