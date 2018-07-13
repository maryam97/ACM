//#define Q441
#ifdef Q441
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int k,num,tc=0;
    int a,b,c,d,e,f;
    while (cin >> k && k) {
        if(tc++) cout << endl;
        //vector<int>numbers;
        int lotto[13];
        for (int i = 0; i < k;i++) {
            cin >> lotto[i];
            //numbers.push_back(num);
        }
        for(int i=0; i<k; i++) cerr << lotto[i]<< " ";
        cerr << endl;

        for ( a = 0; a < k - 5;a++)
            for ( b = a + 1; b < k - 4; b++)
                for ( c = b + 1; c < k - 3; c++)
                    for ( d = c + 1; d < k - 2; d++)
                        for ( e = d + 1; e < k - 1; e++)
                            for ( f = e + 1; f < k ; f++)
                                cout << lotto[a] << " " << lotto[b] << " " << lotto[c]
                                     << " " << lotto[d] << " " << lotto[e]
                                     << " " << lotto[f] << endl;

    }

    return 0;
}

#endif 