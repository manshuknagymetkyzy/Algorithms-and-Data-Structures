#include <iostream>
#include <vector>
using namespace std;

vector<int> g[101];
int table[101];
bool ok;

void dfs(int v, int t){
    table[v] = t;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(table[to] == 0)
            dfs(to, 3 - t);
        else{
            if(table[to] == t)
                ok = false;
        }
    }
}

int main(){
    int n, m, x, y;
    cin >> n >> m;
    ok = true;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0; i < n; i++){
        if(table[i] == 0){
            dfs(i, 1);
        }
    }
    if(ok){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            if(table[i] == 1)
                cout << i + 1 << " ";
        }
    }
    else cout << "NO";
}
