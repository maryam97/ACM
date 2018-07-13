//1203 Argus
//#define Q1203
#ifdef Q1203

#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,int> ppiii;

struct comp{
    bool operator()(ppiii &f, ppiii &s){
        if(f.first.first == s.first.first)
            return f.second > s.second;
        else
            return f.first.first > s.first.first;
    }
};

int main(){
    ios::sync_with_stdio(0);
    string str;
    int id,period,k;
    priority_queue<ppiii,vector<ppiii>,comp>pq;
    while(cin >> str && str!="#"){
        cin >> id >> period;
        pq.push(make_pair(make_pair(period,period),id));
    }
    cin >> k;
    while(k--){
        cout <<pq.top().second<<endl;
        ppiii tmp = pq.top();
        tmp.first.first+=tmp.first.second;
        pq.pop();
        pq.push(tmp);
    }

    return 0;
}
#endif