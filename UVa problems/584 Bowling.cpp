#define Q584
#ifdef Q584

//AC

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    string a;
    while(getline(cin,a)){
        vector<int>vec;
        stringstream str;
        str<<a;
        string d,dd;
        str>>d,str>>dd;
        if(d=="Game" && dd=="Over")
            break;
        stringstream str1;
        str1.clear();
        str1<<a;
        char b;
        while(str1>>b){
            int c;
            if(b=='/')
                c=-1;
            else if(b=='X')
                c=-2;
            else
                c=b-48;
            vec.push_back(c);
        }
        int score=0;
        int frame=0;
        for(int i=0;i<vec.size();){
            frame++;
            if(vec[i]==-2) {
                score += 10;
                if(vec[i+2]==-1)
                    score+=10;
                else if(vec[i+1]==-2){
                    score+=10;
                    if(vec[i+2]==-2)
                        score+=10;
                    else
                        score+=vec[i+2];
                }
                else
                    score += vec[i + 1], score += vec[i + 2];
                if(frame==10)
                    break;
                else
                    i++;
            }
            else if(vec[i+1]==-1){
                score+=10;
                if(vec[i+2]==-2)
                    score+=10;
                else
                    score+=vec[i+2];
                if(frame==10)
                    break;
                else
                    i+=2;
            }
            else{
                score+=vec[i],score+=vec[i+1];
                i+=2;
            }
        }
        cout<<score<<endl;
    }

    return 0;
}

#endif