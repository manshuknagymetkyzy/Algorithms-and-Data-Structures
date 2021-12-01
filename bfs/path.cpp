#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a, b;
    vector<int> g[n + 1];
    vector<int> d(n + 1);
    vector<bool> used(n + 1);
    queue<int> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
            }
        }
    }
    cin >> a >> b;
    a--;
    b--;
    q.push(a);
    used[a] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
    }
    if(!used[b]) cout << -1;
    else cout << d[b];
}