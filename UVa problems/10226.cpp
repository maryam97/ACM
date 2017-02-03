//#define p10226
#ifdef p10226
#include<iostream>
#include<map>
#include<string>
#include<cstdio>
#include <cstring>
using namespace std;
int main() {
    int n;
    scanf("%d\n\n", &n);
    int count;
    map<string, int> mymap;
    for (int i = 0; i < n; i++) {


        count = 0;
        char s[35];

        while (gets(s)) {
            if (strlen(s) == 0)
                break;
            count++;
            if (mymap.count((string(s))) == 0)
                mymap[string(s)] = 1;
            else {
                mymap[string(s)]++;
            }
        }
        for (map<string, int>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
            printf("%s %.4lf\n", (*it).first.data(),
                   (double)(*it).second / (double)count * 100.0);
        }
        if (i != n - 1) {
            cout << endl;
            mymap.clear();
        }

    }
    return 0;
}
#endif
