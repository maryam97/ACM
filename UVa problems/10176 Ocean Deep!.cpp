//
// Created by maryam on 8/28/17.
//
//#define Q10176
#ifdef Q10176

#include "bits/stdc++.h"
using namespace std;

long long fast_pow(int a,int n, int mod)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
        {result = result*value;
            result = result%mod;}
        value = value*value;
        value = value%mod;
        power /= 2;
    }
    return result;
}

int main(){
    string str;
    char c;
    while((c = getchar()) != EOF){
        if(c == '#') {
            int ans = 0;
            int sz = str.size() - 1, p = 0;
            for (int j = sz ; j >= 0; --j) {
                if (str[j] == '1')
                    ans = (ans + fast_pow(2, p, 131071)) % 131071;
                p++;
            }

            if (ans == 0) cout << "YES\n";
            else cout << "NO\n";
            str = "";
        }
        if(c != '\n')
            str += c;
    }
}

#endif
