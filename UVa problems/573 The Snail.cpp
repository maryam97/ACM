    //573 The Snail
    //#define Q573
    #ifdef Q573
    #include <iostream>

    using namespace std;

    int main(){
        ios::sync_with_stdio(0);
        double height,climb,slide,fat;
        while(cin >> height >> climb >> slide >> fat && height){
            double dec = climb * fat * 0.01;
            int day = 0;double h = 0.0; double climb1;
            while(1){
                if(climb - day*dec < 0) climb1 = 0;
                else
                    climb1 = climb - day*dec;
                h += climb1;
                if( h > height ){
                    cout << "success on day " << day+1 <<endl;
                    break;
                }
                h -= slide;
                if(h < 0) {
                    cout << "failure on day " << day+1 << endl;
                    break;
                }
                day++;
            }//while(1);

        }

        return 0;
    }
    #endif