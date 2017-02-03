//454 Anagrams
//#define Q454
#ifdef Q454

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    cin.get();
    cin.ignore();
    string str;
    map<string,vector<string>> anagram;
    while(tc --){
        anagram.clear();
        vector<string>ans;
        while(getline(cin,str) && str.length()!= 0){
            string str1 = str;
            sort(str.begin(),str.end());
            //remove_if(str.begin(),str.end(),' ');
           // cerr << " ... " << str << " ... " <<endl;
            str.erase(remove(str.begin(), str.end(), ' '), str.end());
            //cout << " ..." << str << "... " <<endl;
            anagram[str].push_back(str1);
        }
        map<string,vector<string>>::iterator it;
        for(it=anagram.begin();it!=anagram.end();it++){
            vector<string>pairs = it->second;
            sort(pairs.begin(),pairs.end());
            if(pairs.size() != 1){
                for(int j = 0; j < pairs.size() - 1; j++){
                    for(int i = j+1; i < pairs.size(); i++){
                        //answer = pairs[j] + " = " + pairs[i];
                        ans.push_back(pairs[j] + " = " + pairs[i]);
                    }
                    //cerr << answer << endl;
                }
            }
        }
        sort(ans.begin(),ans.end());
        for (int k = 0; k <ans.size(); k++) {
            cout << ans[k] <<endl;
        }
        if(tc) cout <<endl;
    }

    return 0;
}


#endif