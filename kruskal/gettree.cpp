#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
int n = 10;

vector<int> p (105);

int dsu_get (int v) {
	if (v == p[v]) return v;
	return p[v] = dsu_get(p[v]);
}

void dsu_unite (int a, int b) {
	a = dsu_get (a); //a = 1
	b = dsu_get (b); //b = 2
	if (rand() & 1) 
		swap (a, b); //a = 1, b = 2
	if (a != b)
		p[a] = b;
}


int main(){
	int n, m;
	cin >> n >> m;
	vector < pair < int, pair<int,int> > > g; 
	int cost = 0;
	vector < pair<int,int> > res;
	for (int i = 0; i < m; i ++){
		int u, v, w;
		cin >> u >> v;
		// cout << u << v << w << endl;
		g.push_back({1, {u,v}});
		// g.push_back({1, {v,u}});
	}
  	sort (g.begin(), g.end());
 //  	cout << g.size() << endl;
	// for (int i = 0; i < g.size(); i ++){
	// 	cout << g[i].first << "  (" << g[i].second.first << ", " << g[i].second.second << ")" << endl;
	// }
	p.resize (n);
	for (int i=0; i<=n; ++i){
		p[i] = i;
	}
	for (int i=0; i<m; ++i) {
		int a = g[i].second.first;
		int b = g[i].second.second;
		int l = g[i].first;	
		
		if (dsu_get(a) != dsu_get(b)) {
			// cout << g[i].second.first << " " << g[i].second.second << endl;
			cost += l;
			res.push_back (g[i].second);
			dsu_unite (a, b);
		}
	}

	for (int i = 0; i < res.size(); i ++){
		cout << res[i].first << " " << res[i].second << endl;
	}
}
