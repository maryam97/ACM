//#define Q115532
#ifdef Q115532

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    int n;
    int arr[8][8];
    while(tc--) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                arr[i][j] = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        int which[8]={0,1,2,3,4,5,6,7};
        int minn=1000000;
        do{
            int sum=0;
            for(int i=0; i<n; i++){
                sum+=arr[i][which[i]];
            }
            minn=min(minn,sum);
        }while(next_permutation(which,which+n));
        cout << minn << endl;

    }


        return 0;
}


#endif

