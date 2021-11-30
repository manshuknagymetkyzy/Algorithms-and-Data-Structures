#include <iostream>
#include <vector>
using namespace std;

vector<int> g[101];
bool used[101];
int cnt;

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
    int n, s;
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
            }
        }
    }
    dfs(s);
    cout << cnt - 1;
}