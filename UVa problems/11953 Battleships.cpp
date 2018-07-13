//#define Q11953
#ifdef Q11953

#include <bits/stdc++.h>
using namespace std;

int dy[]={-1,1};
int dx[]={-1,1};
int n,X=0;
vector<vector<char>>grid;
int ff_up(int r, int c){
    int cnt = 0;
    if(r < 0 || r >= n || c < 0 || c >= n)
        return 0;
    if(grid[r][c] != '@' && grid[r][c] != 'x') return 0;
    cnt ++ ;
    if(grid[r][c] == 'x') X++;
    grid[r][c] = '#';
    for (int i = 0; i < 2; ++i) {
        ff_up(r,c+dy[i]);
    }

    if(X == 0) cnt = 0;
    return cnt;
}
int ff_right(int r, int c){
    int cnt = 0;
    if(r < 0 || r >= n || c < 0 || c >= n)
        return 0;
    if(grid[r][c] != '@' && grid[r][c] != 'x') return 0;
    cnt ++ ;
    if(grid[r][c] == 'x') X++;
    grid[r][c] = '#';
    for (int i = 0; i < 2; ++i) {
        ff_right(r+dx[i],c);
    }
    if(X==0) cnt = 0;
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    char c;
    for (int t = 1; t <= tc; ++t) {
        cin >> n;
        grid.clear();
        grid.resize(n,vector<char>(n));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> grid[j][k];
            }
        }
        cout << "Case " << t << ": ";
        char c3 = '#';
        int ans = 0;
        for (int l = 0; l < n; ++l) {
            for (int j = 0; j < n; ++j) {
                char now = grid[l][j];
                if(grid[l][j] != c3 && grid[l][j] != '.')
                {
                    X=0;
                    int up = ff_up(l,j);
                    grid[l][j] = now,X=0;
                    int right = ff_right(l,j);
                    if(up != 0 || right != 0)
                        ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
#endif