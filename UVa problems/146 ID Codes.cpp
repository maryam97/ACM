
//#define Q146
#ifdef Q146

#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    while (cin >> str && str != "#"){
        string str1 = str;
        sort(str1.rbegin(),str1.rend());
        if(str == str1)
            cout << "No Successor\n";
        else {
            next_permutation(str.begin(), str.end());
            cout << str << endl;
        }
    }
}

#endif