//637 Booklet Printing

//#define Q637
#ifdef Q637

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int>ii;
int main(){
    ios::sync_with_stdio(0);
    int page;
    while(cin >> page && page){
        cout << "Printing order for "<< page <<" pages:\n";
        int sheet=0;
        if(page%4 == 0) sheet = page/4;
        else sheet = page/4 +1;
        vector<ii>front(sheet,ii(0,0)),back(sheet,ii(0,0));
        for(int i=0,j=0;i<=page,j<sheet;i+=2,j++)
            front[j].second=i+1;
        for(int i=1,j=0;i<=page,j<sheet;i+=2,j++)
            back[j].first=i+1;
        for(int i=4*sheet-1,j=0;i>0,j<sheet;i-=2,j++)
            if(i<=page) back[j].second=i;
        for(int i=4*sheet,j=0;i>0,j<sheet;i-=2,j++)
            if(i<=page) front[j].first=i;

        if (page == 1) {
            back[0].first=0;
            }

            for (int i = 0; i < sheet; i++) {
                if (front[i].first != 0 || front[i].second != 0) {
                    cout << "Sheet " << i + 1 << ", front: ";
                    if (front[i].first == 0) cout << "Blank, ";
                    else cout << front[i].first << ", ";
                    if (front[i].second == 0) cout << "Blank\n";
                    else cout << front[i].second << endl;
                }

                if (back[i].first != 0 || back[i].second != 0) {
                    cout << "Sheet " << i + 1 << ", back : ";
                    if (back[i].first == 0) cout << "Blank, ";
                    else cout << back[i].first << ", ";
                    if (back[i].second == 0) cout << "Blank\n";
                    else cout << back[i].second << endl;
                }
            }
    }

    return 0;
}

#endif