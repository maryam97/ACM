//#define Q10855
#ifdef Q10855

#include<bits/stdc++.h>

using namespace std;

typedef vector<char> vi;
typedef vector<vi> vvi;

int n,m;

int available(vvi a,vvi b){
    bool check=true;
    int num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int khak=0;
            for(int k=0;k<m;k++){
                for(int d=0;d<m;d++){
                    if(i+k<n && j+d<n) {
                        if (a[i + k][j + d] == b[k][d]) {
                            khak++;
                        }
                    }
                }
            }
            if(m*m==khak)
                num++;
        }
    }
    return num;
}

void rotate( vvi &b){
    vvi tmp=b;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            b[i][j]=tmp[m-j-1][i];
        }
    }
}

int main(){

    ios::sync_with_stdio(0);

    while(cin>>n>>m && (n || m)){
        vvi a(n,vi(n)),b(m,vi(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                cin>>b[i][j];
            }
        }
        cout<<available(a,b)<<" ";rotate(b);
        cout<<available(a,b)<<" ";rotate(b);
        cout<<available(a,b)<<" ";rotate(b);
        cout<<available(a,b)<<endl;
    }

    return 0;
}

#endif