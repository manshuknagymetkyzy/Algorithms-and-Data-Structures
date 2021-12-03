#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, s, f;
    const int INF = 1e6;
    cin >> n >> s >> f;
    s--;
    f--;
    vector<pair<int, int> > g[n];
    vector<int> d(n, INF);
    vector<int> p(n);
    vector<bool> used(n);
    for(int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            int x;
            cin >> x;
            if (x != -1 && x != 0){
                g[i].push_back(make_pair(j, x));
            }
        }
    }
    d[s] = 0;
    for (int i = 1; i <= n; i++){
        int v = -1;
        for (int j = 0; j < n; j++){
            if (!used[j] && (v == -1 || d[j] < d[v])){
                v = j;
            }
        }
        if (d[v] == INF) break;
        used[v] = true;
        for (int j = 0; j < g[v].size(); j++){
            int to =  g[v][j].first;
            int distance = g[v][j].second;
            if (d[v] + distance < d[to]){
            d[to] = d[v] + distance;
            }
        }
    }
    if (d[f] != INF){
        cout << d[f] << endl;
    }
    else{
        cout << -1 << endl;
    }
}