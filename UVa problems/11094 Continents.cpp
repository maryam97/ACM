//#define Q11094
#ifdef Q11094

#include <bits/stdc++.h>

using namespace std;
char now;
int count = 0;
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
int M,N,X,Y;
vector<vector<char>>graph;

int flood_fill(int r,int c,char c1,char c2){
    int ans = 1;
    graph[r][c] = c2;
    int y;
    for (int i = 0; i < 4; ++i) {
        if(r+dx[i] < 0 || r+dx[i] >= M) continue;
        if(c+dy[i]==-1) y=N-1;
        else if(c+dy[i]==N) y=0;
        else y=c+dy[i];
        if(graph[r+dx[i]][y]==now) ans+=flood_fill(r+dx[i],y,c1,c2);
    }

    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    while(cin >> M >> N){
        int mx = 0;
        graph.clear();
        graph.resize(M,vector<char>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> graph[i][j];
            }
        }
        cin >> X >> Y;
        now = graph[X][Y];
        flood_fill(X,Y,now,'0');
        for (int k = 0; k < M; ++k) {
            for (int i = 0; i < N; ++i) {
                if(graph[k][i] == now)
                    mx = max(mx,flood_fill(k,i,now,'0'));
            }
        }
        cout << mx << endl;
        cin.ignore();
    }

    return 0;
}

#endif