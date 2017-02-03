
//#define Q1062
#ifdef Q1062

#include<bits/stdc++.h>

using namespace std;

typedef stack<char> si;
typedef vector<si> vsi;

int main(){

    ios::sync_with_stdio(0);

    string a;
    int Case=1;
    while(cin>>a){
        if(a=="end")
            break;
        vsi vec;
        for(auto & i:a){
            if(vec.size()){
                bool yes=false;
                for(auto & j:vec){
                    if(j.top()>=i) {
                        j.push(i);
                        yes=true;
                        break;
                    }
                }
                if(!yes){
                    si s;
                    s.push(i);
                    vec.push_back(s);
                }
            }
            else{
                si s;
                s.push(i);
                vec.push_back(s);
            }
        }
        cout<<"Case "<<Case++<<": "<<vec.size()<<endl;
    }
    return 0;
}

#endif