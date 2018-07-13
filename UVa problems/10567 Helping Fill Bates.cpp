//#define Q10567
#ifdef Q10567

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    string S,str; cin >> S;
    bool match;
    int x,tc; cin >> tc;
    vector<vector<int>>indx(52);
    for (int i = 0; i < S.size(); ++i) {

        if((int)S[i] >= 97)
            indx[S[i]-97].push_back(i);
        else indx[S[i]-39].push_back(i);
    }
    size_t first=0,last=0;
    while(tc--){
        match=true;
        int id;
        cin >> str;
        if((int)str[0]>=97) {
            if (indx[str[0] - 97].size() == 0) match = false;
        }
        else {
            if(indx[str[0]-39].size()==0) match=false;
        }
        if(match) {
            if((int)str[0]>=97)  id=indx[str[0]-97][0];
            else id=indx[str[0]-39][0];
            for (int i = 1; i < str.size(); i++) {
                if ((int) str[i] >= 97) {
                    if (indx[str[i] - 97].size() == 0) match = false;
                } else {
                    if (indx[str[i] - 39].size() == 0) match = false;
                }

                if (match) {
                    if ((int) str[i] >= 97) {
                        int pos = upper_bound(indx[str[i] - 97].begin(), indx[str[i] - 97].end(), id) -
                                  indx[str[i] - 97].begin();
                        if (indx[str[i] - 97][pos] > id) {
                            id = indx[str[i] - 97][pos];
                        } else {
                            match = false;
                        }
                    } else {
                        int pos = upper_bound(indx[str[i] - 39].begin(), indx[str[i] - 39].end(), id) -
                                  indx[str[i] - 39].begin();
                        if (indx[str[i] - 39][pos] > id) {
                            id = indx[str[i] - 39][pos];
                        } else {
                            match = false;
                        }
                    }
                    first = S.find(str[0]);
                    last = id;
                }
            }
        }
        if(match) cout << "Matched "<<first<<" "<<last<<endl;
        else cout << "Not matched\n";
    }

    return 0;
}

#endif