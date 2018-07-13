//11565 - Simple Equations
//#define Q11565
#ifdef Q11565

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int a,b,c;

    int tc; cin >> tc;
    while(tc--){
        int X=110,Y=110,Z=110;
        cin >> a >> b >> c;
        for (int x = -22; x <= 22; x++){if(x*x < c)
            for(int y = -100; y <=100; y++) if(x!=y && x*x + y*y < c )
                for(int z=-100;z<=100; z++) if(x!=y && y!=z && x!=z && x+y+z==a && x*y*z==b && x*x+y*y+z*z==c) {
                        //cerr << " x " << x <<" X " << X <<endl;
                        if (x < X) X = x, Y = y, Z = z;
                        else if(x == X) {
                            if(y<Y) Y=y,Z=z;
                        }
                    }

        }
        if(X>Y) swap(X,Y);
        if(X==110 || Y==110 || Z==110) cout << "No solution.\n";
        else cout << X << " " << Y << " " << Z << endl;
    }



    return 0;
}


#endif