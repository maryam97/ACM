//#define Q12085
#ifdef Q12085

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    vector<string> str,seq;
    vector<int> in;
    int n,tc=1;
    while(cin>>n && n){
        str.clear();seq.clear();
        while(n--) {
            cin >> s;
            str.push_back(s);
            in.push_back(stoi(s));
        }
        cout << "Case " << tc++ << ":" << endl;
        int i;
        for (i = 0 ; i<in.size()-1; i++) {
            seq.clear();
            if (in[i + 1] - in[i] > 1) {
                cout << str[i] << endl;
            }
            else {
                //seq.clear();
                int ii=i;
                while (in[ii + 1] - in[ii] == 1) {
                    seq.push_back(str[ii]);
                    ii++;
                }
                if (ii != i)
                    seq.push_back(str[ii]);
                i = ii;
                cerr << "pocker\n";
                int same = 0;
                for (int k = 0; k < seq[0].size(); k++) {
                    if(seq[0][k] != seq[seq.size()-1][k]) {
                        same = k;
                        break;
                    }
                }
                cerr << same <<endl;
                cout << seq[0];
                cout << "-";
                for (int h = same; h < seq[seq.size() - 1].size(); h++) {
                    cout << seq[seq.size() - 1][h];
                }
                cout << endl;
            }
            seq.clear();
        }
        if (i < str.size())
            cout << str[str.size() - 1] << endl;
        cout << endl;
    }

    return 0;
}

#endif