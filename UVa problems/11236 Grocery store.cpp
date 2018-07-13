//11236 Grocery store
//#define Q11236
#ifdef Q11236

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);

    for(int x=1; 4*x<=2000;x++){
        for(int y=x; 3 * y<=2000-x; y++){ //if(x*y>=10000 && x+y<2000 )
            for(int z=y; 2*z<=2000-x-y; z++){
                //if(x*y*z>=1000000 && x+y+z<=2000) {
                    int sum = x + y + z;
                    int pro = x * y * z;
                    if(pro <= 1000000) continue;
                    if ((1000000 * sum) % (pro - 1000000)!=0) {
                        continue;
                    }
                    int t = (1000000 * sum) / (pro - 1000000);
                        //cerr << t << endl;
                    if (t < z || t+sum > 2000)
                        continue;
                    cout << fixed << setprecision(2) << x / 100.0 << " " << y / 100.0 << " " << z / 100.0 << " "
                             << t / 100.0 << endl;


                //}
            }
        }
    }

    return 0;
}


#endif