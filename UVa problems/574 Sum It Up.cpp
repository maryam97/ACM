//574 Sum It Up
//#define Q574
#ifdef Q574

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi temp(12),ans,num(12);
int sum,n,number;
set<vi> answer;

void solution(int i,int j,int cur){
    //cerr << cur << "   " << number <<endl;
    if(cur == number){
        ans.clear();
        for (int k = 0; k <= i; ++k) {
            ans.push_back(temp[k]);
            //cerr << temp[k] <<endl;
        }
        sort(ans.rbegin(),ans.rend());
        answer.insert(ans);
    }
    for (int k = j+1; k <n ; ++k) {
        if(cur+num[k] <= number){
            temp[i+1] = num[k];
            solution(i+1,k,cur+num[k]);
        }
    }


}
int main(){
    ios::sync_with_stdio(0);
    while(cin >> number >> n && (number||n) ){
        answer.clear();
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        for (int j = 0; j < n; ++j) {
            sum=0;
            temp[0]=num[j];
            solution(0,j,num[j]);
        }
        cout << "Sums of "<<number<<":\n";
        if(answer.size() == 0) cout << "NONE\n";
        else {
            set<vi>::reverse_iterator it;
            for (it = answer.rbegin(); it != answer.rend(); it++) {
                for (int i = 0; i < (*it).size() - 1; ++i) {
                    cout << (*it)[i] << "+";
                }
                cout << (*it)[(*it).size() - 1] << endl;
            }
        }
    }

    return 0;
}

#endif