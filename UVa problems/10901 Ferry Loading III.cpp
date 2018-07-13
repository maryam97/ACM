//                                    to check

#define p10901
#ifdef p10901

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    queue<pair<int,int>> right,left;
    while(tc--){

        int n,t,m,i=0,num=0;
        int time = 0;
        int location = 0; // left
        cin>>n>>t>>m;
        vector<int> vec(m);
        while(m--){
            int T; string s;
            cin>>T>>s;
            if (s =="left"){
                left.push(make_pair(i++,T));
            }else{
                right.push(make_pair(i++,T));
            }
        }
       while(!left.empty() || !right.empty()){
            if (location == 1) { // right
                num = 0;
                while (num <= n && !right.empty() && right.front().second <= time ) {
                    vec[right.front().first] = time + t;
                    right.pop();
                    location = 0;
                    num++;
                }
                if (!num) {
                    if (right.empty() || (!left.empty() && left.front().second < right.front().second)) {
                        if (left.front().second > time) {
                            time = left.front().second;
                            location = 0;
                        }
                    }
                    else if(left.empty() || right.front().second <=left.front().second ){
                        time=right.front().second;
                        continue;
                    }
                }
            }
           if (location ==0) { //left
               num = 0;
               while (num <= n && !left.empty() && left.front().second <= time ) {
                   vec[left.front().first] = time + t;
                   location = 1;
                   left.pop();
                   num++;
               }
               if(!num) {
                   if (left.empty() || (!right.empty() && right.front().second < left.front().second)) {
                       if (right.front().second > time) {
                           time = left.front().second;
                           location = 1;
                       }
                   }
                   else if(right.empty() || left.front().second <= right.front().second){
                       time=left.front().second;
                       continue;
                   }
               }
           }
           time += t;
        }
        for (int i=0;i<vec.size();i++){
            cout<<vec[i]<<endl;
        }
        if (tc)
            cout<<endl;
    }
    return 0;
}


#endif