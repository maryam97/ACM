//#define Q11489
#ifdef Q11489

#include "bits/stdc++.h"
using namespace std;

/*int sol(int i, int id, string str, int sum){
    if(str.size() == 1)  return id; //return (sum % 3) ? id : (1 - id);
    if(sum % 3 && sum != -1) return -1;
    if(i == -1) return -1;
    int len = (int)str.size();
    int ans, answer = -1;
    //for (int i = 0; i < len; ++i) {
        string s = "";
        int sumation = 0;
        for (int j = 0; j < len; ++j) {
            if(i != j) {
                s += str[j];
                sumation += (str[j] - 48);
            }
        }
        ans = sol(i-1, 1 - id, s, sumation);
        if(ans != -1) {
            answer = ans;
            //break;
        }
    //}
    return answer;
}*/
int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
   for(int t = 1; t <= tc; t++){
        string str;
        cin >> str;
        //int ans = sol((int)str.size() - 1,0, str, -1);
       int id = 0;
       vector<int> vec,vis(str.size(),0);
       int sum = 0;
       for (int i = 0; i < str.size(); ++i) {
           vec.push_back(str[i]-48);
           sum += vec[i];
       }
       while(sum) {
           id = 1 - id;
           bool ok = false;
           for (int i = 0; i < vec.size(); ++i) {
               if (!vis[i] && ((sum - vec[i]) % 3 == 0)){
                    sum -= vec[i];
                   vis[i] = 1;
                   ok = true;
                   break;
               }
           }
           if(!ok) {
               id = 1 - id;
               break;
           }

       }

       cout << "Case " << t;
        if(id)  cout << ": S\n";
        else cout << ": T\n";
    }


    return 0;
}


#endif