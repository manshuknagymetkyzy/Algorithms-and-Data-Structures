#include <iostream>
#include <queue>
using namespace std;
int n;

bool isOk(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}

int main(){
    int x1, y1, x2, y2;
    const int INF = 1000000;
    cin >> n;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    queue<pair<int, int> > q;
    int d[25][25];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = INF;
        }
    }
    d[x1][y1] = 0;
    q.push(make_pair(x1, y1));
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k = 0; k < 8; k++){
            int toX = i + dx[k];
            int toY = j + dy[k];
            if(isOk(toX, toY) && d[toX][toY] > d[i][j] + 1){
                d[toX][toY] = d[i][j] + 1;
                q.push(make_pair(toX, toY));
            }
        }
    }
    cout << d[x2][y2];
}