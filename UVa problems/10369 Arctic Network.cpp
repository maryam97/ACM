//#define Q10369
#ifdef Q10369

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<int> ufds;
vector<pair<double, ii>> graph;
int sat,counter,outpost;
void buildUfds(int n) {
    ufds.clear(); ufds.resize(n);
    for(int i = 0; i < n; i++) ufds[i] = i;
}

int findSet(int i) {
    return (ufds[i] == i) ? i : (ufds[i] = findSet(ufds[i]));
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

void joinSets(int i, int j) {
    int a = findSet(i), b = findSet(j);
    if (a < b) ufds[a] = b;
    else ufds[b] = a;
}

double kruskal() {
    double cost = 0;
    for(int i = 0; i < graph.size() ; i++) {
        pair<double, ii> fr = graph[i];
        if(!isSameSet(fr.second.first, fr.second.second)) {
            if(outpost == sat) break;
            --outpost;
            cost = fr.first;
            joinSets(fr.second.second, fr.second.first);
        }
    }
    return cost;
}

int main(){
    ios::sync_with_stdio(0);
    int N;cin >> N;
    int x,y;
    while(N--){
        counter = 0;
        graph.clear();
        vector<ii>tmp;
        cin >> sat >> outpost;
        for (int i = 0; i < outpost; ++i) {
            cin >> x >> y;
            tmp.push_back(make_pair(x,y));
        }
        for (int j = 0; j < outpost; ++j) {
            for (int i = j+1; i < outpost; ++i) {
                double dist = hypot(tmp[j].first-tmp[i].first,tmp[j].second-tmp[i].second);
                graph.push_back(pair<double,ii>(dist,ii(j,i)));
            }
        }
        sort(graph.begin(),graph.end());
        buildUfds(outpost);
        cout << fixed << setprecision(2) <<  kruskal() << endl;
    }

    return 0;
}

#endif