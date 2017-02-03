//156 Ananagrams
//#define Q156
#ifdef Q156
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    string str;
    map<string,string> main;
    map<string,int> repeat;
    vector<string> lowers;
    vector<string>ans;
    while(cin >> str && str != "#"){
        string str1 = str;
        transform(str.begin(),str.end(),str.begin(),::tolower);
        //cerr << str <<" ";
        sort(str.begin(),str.end());
        lowers.push_back(str);
        main[str] = str1;
    }
    //sort(lowers.begin(),lowers.end());
    for (int i = 0; i < lowers.size(); i++) {
        ++repeat[lowers[i]];
    }

    map<string,int>::iterator it;
    for( it = repeat.begin(); it!=repeat.end(); it++){
        if(it->second == 1){
            ans.push_back(main[it->first]);
        }
    }
    sort(ans.begin(),ans.end());
    for (int j = 0; j < ans.size(); j++) {
        cout << ans[j] <<endl;
    }

    return 0;
}

#endif

