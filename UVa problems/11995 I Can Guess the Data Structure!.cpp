//11995 I Can Guess the Data Structure!
//#define Q11995
#ifdef Q11995
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int tc;
    int which,num;
    while(cin >> tc){
        bool stck=true, que=true, pque=true;
        queue<int>q;
        stack<int>s;
        priority_queue<int>pq;
        while(tc--){
            cin >> which >> num;
            if(which == 1){
                s.push(num);
                q.push(num);
                pq.push(num);
            }
            else{
                if( stck && !s.empty() && (s.top() == num)) s.pop();
                else stck = false;
                if(que && !q.empty() && q.front() == num) q.pop();
                else que = false;
                if( pque && !pq.empty() && pq.top() == num) pq.pop();
                else pque = false;
            }
        }
        if((stck && que) || (stck && pque) || (que && pque) || (stck && que && pque))
            cout << "not sure\n";
        else if(stck)
            cout << "stack\n";
        else if(que)
            cout << "queue\n";
        else if(pque)
            cout << "priority queue\n";
        else
            cout << "impossible\n";
    }
    return 0;
}
#endif