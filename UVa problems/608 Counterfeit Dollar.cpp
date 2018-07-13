
//#define Q608
#ifdef Q608

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int tc; cin>>tc;
    string str,str1,str2;
    while(tc--) {
        map<char, int> up, down,even;
        for (int i = 0; i < 3; i++) {
            cin >> str1 >> str2 >> str;

            if (str == "even") {
                for (auto &i:str1)
                    ++even[i];
                for (auto &j:str2)
                    ++even[j];
            } else if (str == "up") {
                for (auto &k:str2)
                    ++up[k];
                for (auto &k:str1)
                    ++down[k];
            } else if (str == "down") {
                for (auto &k:str1)
                    ++up[k];
                for (auto &k:str2)
                    ++down[k];
            }
        }
        int i;int mx,w;
        char c;
        pair<int,pair<char,int>>ans;
        for( char i='A';i<'M';i++){
            //cerr<<"----- "<< i<<endl;
            if(even.count(i) == 0){
                if(up[i] > down[i]){
                    //c=(char)(i+6);
                    mx=up[i];
                    w=0; //up
                }
                else {
                    //c=(char)(i+65);
                    mx=down[i];
                    w=1; //down
                }
                if(mx>ans.second.second){
                    ans.second.second=mx;
                    ans.second.first=i;
                    ans.first=w;
                }
            }
        }
        if(ans.first!=0){
            cout <<(ans.second.first)<<" is the counterfeit coin and it is heavy."<<endl;
        } else
            cout <<(ans.second.first)<<" is the counterfeit coin and it is light."<<endl;

    }


    return 0;
}


#endif
