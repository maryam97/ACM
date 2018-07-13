//12356 Army buddies
//#define Q12356
#ifdef Q12356

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    vector<int>soldier;
    map<int,int>left,right;
    int S,B,x,y;
    while(cin >> S >> B && (S||B)){
        soldier.clear();
        right.clear();
        left.clear();
        for(int i=1; i<=S; i++){
            soldier.push_back(i);
            left[i+1]=i;
            right[i-1]=i;
        }
        for(int i=0;i<B;i++){
            cin >> x >> y;
            right[left[x]]=right[y];
            left[right[y]]=left[x];
            if(left[x]==0) cout << "* ";
            else cout << left[x] << " " ;
            if(right[y]==0) cout <<"*\n";
            else cout << right[y] <<endl;
        }
        cout <<"-\n";
    }

    return 0;
}

#endif