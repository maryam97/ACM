//#define Q481
#ifdef Q481

#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    int num;
    vector<int>seq;
    while(cin>>num){
        seq.push_back(num);
    }
    int len=0,end=0;
    vector<int>tail(seq.size());
    vector<int>suc(seq.size());
    vector<int>l_id(seq.size());
    for (int i = 0; i < seq.size(); ++i) {
        int pos = lower_bound(tail.begin(),tail.begin()+len,seq[i])-tail.begin();
        tail[pos]=seq[i];
        l_id[pos]=i;
        suc[i] = (pos) ? l_id[pos-1] : -1;
        if(pos+1>len){
            len = pos+1;
            end=i;
        }
    }

    stack<int>s;
    int j=0;
    for (j = end; suc[j]>=0 ; j=suc[j]) {
        s.push(seq[j]);
    }
    int Size=len;
    cout << Size << endl << "-\n";
    cout << seq[j]<<endl;
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}

#endif