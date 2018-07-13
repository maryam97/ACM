/*#define p12085
#ifdef p12085

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    vector<string> str, seq;
    vector<int> in;
    int n;
    int cs = 1;
    while (cin >> n && n) {
        str.clear();
        in.clear();
        while (n--) {

            cin >> s;
            str.push_back(s);
            in.push_back(stoi(s));
        }
        cout << "Case " << cs++ << ":\n";
        int i;
        for (i = 0; i < in.size() - 1; i++) {
            if (in[i + 1] - in[i] > 1)
                cout << str[i] << endl;
            else {
                int ii = i;
                while (in[ii + 1] - in[ii] == 1)
                    seq.push_back(str[ii]), ii++;
                if (ii != i)
                    seq.push_back(str[ii]);
                i = ii;
                int num = 0;
                for (int k = 0; k < seq[0].size(); k++) {
                    if (seq[0][k] != seq[seq.size() - 1][k]) {
                        num = k;
                        break;
                    }
                }
                cout << seq[0];
                cout << "-";
                for (int k = num; k < seq[seq.size() - 1].size(); k++)
                    cout << seq[seq.size() - 1][k];
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
 */