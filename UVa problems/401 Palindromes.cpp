//401 Palindromes
//#define Q401
#ifdef Q401

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    /*char array[35] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
                      'Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9'};*/
    char map[35] = {'A','#','#','#','3','#','#','H','I','L','#','J','M','#','O','#',
                    '#','#','2','T','U','V','W','X','Y','5','1','S','E','#','Z','#','#','8','#'};
    string str;

    while(cin >> str){
        bool reg = false, mirror = true;
        string main = str;
        reverse(str.begin(),str.end());
        if(str == main) reg = true;
        for(int j = 0; j < str.length(); j++){
            if((int)str[j] >=65) {
                //cerr << main[j] << "  " << map[(int) str[j] - 65] << endl;
                if (main[j]!= map[(int) str[j] - 65]){
                    mirror = false;
                    break;
                }
            }
            else {
                //cerr << main[j] << "  " << map[(int) str[j] - 23] << endl;
                if (main[j] != map[(int) str[j] - 23]){
                    mirror = false;
                    break;
                }
            }
        }
        if(reg && mirror) cout << main << " -- is a mirrored palindrome.\n";
        else if (reg && !mirror) cout << main << " -- is a regular palindrome.\n";
        else if(!reg && mirror) cout << main << " -- is a mirrored string.\n";
        else if (!reg && !mirror) cout << main << " -- is not a palindrome.\n";
        cout <<endl;


    }
    return 0;
}

#endif