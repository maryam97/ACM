//11459 Snakes and Ladders
//#define Q11459
#ifdef Q11459
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    //vector<int>table(101,0);
    size_t table[100];
    //size_t place[1000000];
    vector<int>place;
    int tc;cin >> tc;
    int player,snklad,die,src,dist,num;
    while(tc--){
       // for(int i=1;i<=100;i++)
         cin >> player >> snklad >> die;
         //  table[i]=i;
        memset(table,0,sizeof(size_t) * 100);
        int i(0);
        //for (i=0; i < player; ++i)
          //  place[i] = 1;
        place.clear();
        place.resize(player,1);

        while(snklad--) {
            cin >> src >> dist;
            table[src]=dist;
        }
        bool gameover=false;
        i=0;
        while(die--){
            cin >> num;
            if (!gameover) {
                place[i]+= num;
                if (place[i]>=100){
                    place[i] = 100;
                    gameover = true;
                }
                else if(table[place[i]]) {
                    place[i] = table[place[i]];
                    if (place[i] >= 100) {
                        place[i] = 100;
                        gameover = true;
                    }

                }
                /*
                if (place[(i % player)] + num < 100) {
                    place[(i % player)] = table[place[(i % player)] + num];
                    if (place[(i % player)] >= 100) gameover = true;
                } else gameover = true;*/
                i = (i+1)%player;
            }
        }
        for (int j = 0; j < player; j++) {
            cout << "Position of player "<< j+1 << " is " << place[j]<<".\n";
        }
    }



    return 0;
}

#endif