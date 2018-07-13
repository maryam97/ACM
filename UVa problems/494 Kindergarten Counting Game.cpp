//
// Created by maryam on 9/5/17.
//
//#define Q494
#ifdef Q494

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    /*string str;
    while(getline(cin , str)) {
        for (int i = 0; i < str.size(); ++i) {
            cout << (int) str[i] << endl;
        }
    }*/
    char c;
    int count = 0;
    string s = "";
    while((c = getchar())  !=EOF){
        if(c == '\n') {
            bool ok = true;
            for (int i = 0; i < s.size() - 1; ++i) {
                if((int)s[i] < 65 || (int)s[i] > 122) ok = false;
            }
            if(ok)
                ++count;
            cout << count << endl;
            count = 0;
            s = "";
        }
        else if((int)c != 32){
            s += c;
        }
        else {
            bool ok = true;
            for (int i = 0; i < s.size() - 1; ++i) {
                if((int)s[i] < 65 || (int)s[i] > 122) ok = false;
            }
            if(ok)
              ++count;
            s = "";
        }

    }

    return 0;
}

#endif
