//#define Q1210
#ifdef Q1210
#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

int sieve_size;
bitset<10000010> bs;
vi primes;
map<int,int> num;
void sieve(int upperbound) {
    sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (int i = 2; i <= sieve_size; i++)
        if (bs[i]) {
            // cross out multiples of i starting from i * i!
            for (int j = i * i; j <= sieve_size; j += i) bs[j] = 0;
            if(i == 2)
                primes.push_back(i), num[i]++;
            else {
                int n = i + primes[primes.size() - 1];
                primes.push_back(n), num[n]++, num[i]++;
            }
        }
}

int main(){
    ios::sync_with_stdio(0);
    sieve(10000);
    int n;
    cerr << primes[primes.size()-1] << endl;
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i+2; j < primes.size(); ++j) {
            num[primes[j] - primes[i]]++;
        }
    }
    while(cin >> n && n){
        cout << num[n] << endl;
    }
    return 0;
}

#endif