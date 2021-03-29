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
 
bool dfs(vector<vector<ll>>& adj,vector<ll> &visited,vector<int> & recStack,ll x) {
	
	recStack[x]=true;
	visited[x] = true;
	int n = adj[x].size();
	for (int i = 0;i < n;i++) {
		if (!visited[adj[x][i]]) {
			if (dfs(adj, visited, recStack, adj[x][i])) return true;
		}
		else if (recStack[adj[x][i]]) return true;
	}
	recStack[x] = false;
	return false;
}
bool check(vector<vector<ll>>& adj, vector<ll>& visited) {
	vector<int> recStack(adj.size(), 0);
	for (int j = 0;j < adj.size();j++) {
		
		if (!visited[j]) {
			if (dfs(adj, visited, recStack, j)) return true;
		}
	}
	
	return false;
}
int main() {

	
	int n, m; cin >> n >> m;
	vector<vector<ll>> adj(n);
	vector<ll> visited(n, 0);
	vector<ll> postorder(n, 0);
	for (int i = 0;i < m;i++) {
		ll x, y; cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	
	/*for (auto it : adj) {
		cout << "x is ->> : "<<j<<" ";
		for (auto i : it) {
			//cout << i << " ";
		}
		j++;
			//cout << "\n";
	} */
	
	
	cout << check(adj,visited) << "\n";
	
}
