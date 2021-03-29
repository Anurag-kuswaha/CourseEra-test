#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<unordered_map>
using namespace std;
typedef long long ll;
bool true_ = false;

bool find_path(vector<vector<ll>> adj, ll x, ll y, vector<ll>& visited) {

	if (x == y) { return true; }
	visited[x] = true;
	int n = adj[x].size();
	for (int i = 0;i < n;i++) {
		for (int i = 0;i < n;i++) {
			if (!visited[adj[x][i]]) {
				//cout << adj[x][i] << "\n";

				if (find_path(adj, adj[x][i], y, visited)) return true;
			}
		}
	}
	return false;
}

void dfs(vector<vector<ll>> adj, ll x, vector<ll>& visited) {
	visited[x] = true;
	int n = adj[x].size();
	for (int i = 0;i < n;i++) {
		if (!visited[adj[x][i]]) {
			dfs(adj, adj[x][i], visited);
		}
	}
}
int find_this(vector<vector<ll>> adj, vector<ll>& visited) {

	int count = 0;
	int n = adj.size();
	for (int i = 0;i < n;i++) {
		//cout << "node is : " << i+1 << " :";
		if (!visited[i]) {
		 dfs(adj, i, visited);
		 	count++;
		}
		//cout << "   not visited " << "\n";
	//	int m = adj[i].size();
		//for (int j = 0;j < m;j++) {
		//	if (!visited[adj[i][j]]) {
				
		//	}

		}

	
	
	return count;
}
int main() {

	//int T; cin >> T;
	//while (T--) {
	int n, m; cin >> n >> m;
	vector<vector<ll>> adj(n);
	vector<ll> visited(n, 0);
	for (int i = 0;i < m;i++) {
		ll x, y; cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);

	}
	int j = 0;
	/*for (auto it : adj) {
		cout << "x is ->> : "<<j<<" ";
		for (auto i : it) {
			//cout << i << " ";
		}
		j++;
			//cout << "\n";
	} */
	//cout << " game begin   \n";

	cout << find_this(adj, visited) << "\n";

	//cout << "finised" << "\n";




//}
}
