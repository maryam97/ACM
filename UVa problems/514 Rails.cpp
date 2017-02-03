//514 Rails
//#define Q514
#ifdef Q514

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    stack<int>coach;
    vector<int>number;
    int N,num;

    while(cin >> N && N){
        bool ok = true;
        while(cin >> num && num) {
            for (int j = 1; j <= N; j++) {
                number.push_back(j);
            }
            for (int k = 1; k <= num; k++) {
                coach.push(k);
                number[k - 1] = 0;
            }
            if (coach.top() == num) coach.pop();
            for (int i = 0; i < N - 1; i++) {
                cin >> num;
                for (int k = 1; k <= num; k++) {
                    if (number[k - 1] != 0) {
                        coach.push(k);
                        number[k - 1] = 0;
                    }
                }
                if (coach.top() == num) coach.pop();
                cerr << "eeee\n";
            }
            cerr <<"why?\n";
            if(coach.empty()) cout << "Yes\n";
            else {
                cout << "No\n";
                while (!coach.empty()) coach.pop();
            }
            number.clear();
        }//cerr << "1\n";
        cout << endl;

    }//cout << "hmm\n";


    return 0;
}

#endif