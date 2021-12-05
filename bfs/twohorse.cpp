#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

const int INF = 10000;
int n = 8;
pair<int,int> d[9][9];

bool isOk(int x, int y){
    return x > 0 && y > 0 && x <= n && y <= n;
}


void print(pair<int,int> a){
	cout << a.first << " " << a.second;
}

int main(){
	freopen("input.in", "r", stdin);
	string s, s1;
	cin >> s >> s1;
	int x1 = s[0] - 'a' + 1;
	int y1 = s[1] - 48;
	// cout << x1 << " " << y1 << endl;
	int x2 = s1[0] - 'a' + 1;
	int y2 = s1[1] - 48;
	// cout << x1 << " " << y1 << endl;
	// cout << x2 << " " << y2 << endl;
	// cout << x2 << " " << y2 << endl;
	int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};


	// for (int i = 0; i < n; i ++){
	// 	cout << x1 + dx[i] << " " << y1 + dy[i] << endl;
	// }
	// cout << endl;

	queue<pair<int,int>> q1;
	queue<pair<int,int>> q2;

	q1.push({x1, y1});
	q2.push({x2, y2});

	int cnt = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j ++){
			d[i][j] = {INF, INF};
		}
	}

	d[x1][y1].first = 0;
	d[x2][y2].second = 0;

	while(!q1.empty()){
		int i = q1.front().first;
		int j = q1.front().second;

		for (int k = 0; k < 8; k ++){
			int toX = i + dx[k];
			int toY = j + dy[k];
			if (isOk(toX, toY) && d[toX][toY].first > d[i][j].first + 1){
				d[toX][toY].first = d[i][j].first + 1;
				q1.push({toX, toY});
			}
			// cout << endl;
		}
		// cout << endl;
		q1.pop();
	}	
	while(!q2.empty()){
		int i = q2.front().first;
		int j = q2.front().second;

		for (int k = 0; k < 8; k ++){
			int toX = i + dx[k];
			int toY = j + dy[k];
			if (isOk(toX, toY) && d[toX][toY].second > d[i][j].second + 1){
				d[toX][toY].second = d[i][j].second + 1;
				q2.push({toX, toY});
			}
		}
		q2.pop();
	}

	// for (int i = 1; i <= 8; i ++){
	// 	for (int j = 1; j <= 8; j ++){
	// 		cout << d[i][j].first << " " << d[i][j].second << "   ";
	// 	}
	// 	cout << endl;
	// }
	
	int mn = 10000;
	pair<int,int> ans;
	bool found = false;
	for (int i = 1; i <= 8; i ++){
		for (int j = 1; j <= 8; j ++){
			if (d[i][j].first == d[i][j].second && d[i][j].first < mn){
				mn = d[i][j].first;
				found = true;
				ans = d[i][j];
			}
		}
	}
	if (found) cout << ans.first << endl;
	else cout << -1 << endl;
}