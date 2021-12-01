#include <iostream> 
using namespace std;

char a[55][55];
bool used[55][55];
int n;
int cnt;

int up(int i, int j){
    return a[i + 1][j] == '#'; 
}

int down(int i, int j){
    return a[i - 1][j] == '#';
}

int left(int i, int j){
    return a[i][j - 1] == '#';
}

int right(int i, int j){
    return a[i][j + 1] =='#';
}

void dfs(int i, int j){
    if(used[i][j]) return;
    if(i < 1 || i > n || j < 1 || j > n) return;
    if(a[i][j] == '#') return;
    used[i][j] = true;
    cnt += up(i, j) + down(i, j) + left(i, j) + right(i, j);
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n + 2; i++){
        a[0][i] = '#';
        a[n + 1][i] = '#';
        a[i][0] = '#';
        a[i][n + 1] = '#';
    }
    dfs(1, 1);
    dfs(n, n);
    cout << (cnt - 4) * 5 * 5; 
}