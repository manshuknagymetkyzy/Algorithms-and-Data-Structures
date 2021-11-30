#include <iostream>
#include <vector>
using namespace std;

vector<int> g[101];
bool used[101];
int cnt;
int edge;

void dfs(int v){
    if(used[v]) return;
    used[v] = true;
    cnt++;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        dfs(to);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
                edge++;
            }
        }
    }
    dfs(1);
    if(cnt == n && edge / 2 == n - 1) cout << "YES";
    else cout << "NO";
}