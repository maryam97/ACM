//11553 Grid Game
//#define Q11553
#ifdef Q11553

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    int n;
    int arr[8][8];
    while(tc--){
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                arr[i][j]=0;
        cin >> n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> arr[i][j];

        int t=0,i=0,ans=1010;
        int mx1=-1010,mx2=-1010;
        int minn=1010;
        bool b=false;
        while(i<n){
            int sum=0;
            for(int j=i;j<i+1;j++){
                for(int k=i;k<n;k++){
                    if(t && (j==i || k==i))
                        continue;
                    else{
                        cerr << "arr " << arr[j][k] <<endl;
                        //sum+=arr[j][k];
                        if(arr[i][j]<minn)
                            minn=arr[i][j];
                        /*if(sum<0)
                            mx1=max(mx1,sum);
                        else
                            mx2=max(mx2,sum);*/
                    }
                }
                sum+=minn;
            }
            if(ans>sum)
                ans=sum;
            cerr << "sum " << sum <<endl;
            cerr << "-------------------"<<endl;
            t++;
            if(t) i++;
        }
        cerr << "=======================" << endl;
        /*if(mx1==-1010) cout << mx2 <<endl;
        else cout << mx1 << endl;*/
        cout << ans <<endl;
    }
    return 0;
}

#endif