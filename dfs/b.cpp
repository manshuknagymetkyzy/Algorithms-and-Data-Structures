#include <iostream>
#include <vector>
using namespace std;
 
vector<int> g[100001];
vector<int> c[100001];
bool used[100001];
int compcnt;
 
void dfs(int v){
    if(used[v]) return;
    used[v] = true;
    c[compcnt].push_back(v);
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        dfs(to);
    }
}
 
int main(){
    int n, m;
    cin >> n >> m;
    for(int k = 0; k < m; k++){
        int i, j;
        cin >> i >> j;
        g[i].push_back(j);
        g[j].push_back(i);
    }
    for(int k = 1; k <= n; k++){
        if(!used[k]){
            dfs(k);
            compcnt++;
        }
    }
 
    cout << compcnt << endl;
    for(int i = 0; i < compcnt; i++){
        cout << c[i].size() << endl;
        for(int j = 0; j < c[i].size(); j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
