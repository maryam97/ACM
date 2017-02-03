//10107 What is the Median?
//#define Q10107
#ifdef Q10107

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    vector<int>number;
    int num;
    while(cin >> num){
        number.push_back(num);
        int size = number.size();
        sort(number.begin(), number.end());
        if(size % 2 != 0) cout << number[size/2] <<endl;
        else cout << ((number[size/2]+number[size/2-1])/2) << endl;
    }
    return 0;
}

#endif