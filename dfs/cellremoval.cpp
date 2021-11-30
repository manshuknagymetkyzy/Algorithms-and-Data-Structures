#include <iostream>
using namespace std;

char a[101][101];
int n, m, cnt, cnt2;
bool used[101][101];

void dfs(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    if(used[i][j]) return;
    if(a[i][j] == '.') return;
    used[i][j] = 1;
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(used[i][j] != 1 && a[i][j] != '.'){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
}