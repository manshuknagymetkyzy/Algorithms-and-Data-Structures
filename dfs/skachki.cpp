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
    int n, k;
    int x, y;
    cin >> n >> k;
    while(cin >> x){
        if(x == 0) break;
        cin >> y;
        g[x].push_back(y);
    }
    dfs(k);
    if(cnt == n) cout << "Yes";
    else cout << "No";
}