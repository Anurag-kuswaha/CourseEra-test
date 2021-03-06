#include <iostream>
#include <vector>
#include<queue>
#include<set>
using namespace std;
#define INF 1e12
#define ll long long
void dfs_run(vector<vector<ll> >& adj, ll s, vector<ll>& reach) {
    if (reach[s]) return;
    reach[s] = 1;
    for (int i = 0;i < adj[s].size();i++) {
        if (!reach[adj[s][i]]) {
            dfs_run(adj, adj[s][i], reach);
        }
    }
}
void dfs(vector<vector<ll> >& adj, ll s, vector<ll>& reach) {

    dfs_run(adj, s, reach);
}
void shortestpath(vector<vector<ll> >& adj, vector<vector<ll> >& cost, ll s) {
    std::vector<ll> dist(adj.size(), INF);
    dist[s] = 0;
    ll n = adj.size();
    bool cycle = true;

    vector<ll> in_the_cycle(adj.size(), 0);
    //run dfs to check which is the possible path to able to reach from the source;
    vector<ll> reach(adj.size(), 0); //possible to explore or nof from the S;
    dfs(adj, s, reach);
    while (n-- != 0) {

        bool relax = false;

        for (ll i = 0;i < adj.size();i++) {

            for (ll j = 0;j < adj[i].size();j++) {
                ll v = adj[i][j];
                if (reach[v]) {
                    if (dist[v] > (dist[i] + cost[i][j])) {

                        dist[v] = dist[i] + cost[i][j];
                        relax = true;
                        in_the_cycle[v] = 1;
                    }
                }
            }
        }


        if (relax == false) { cycle = false; break; }
    }
    if (cycle == false) {
        for (ll i = 0;i < adj.size();i++) {

            if (reach[i] == 0) cout << "*" << "\n";
            else cout << dist[i] << "\n";
        }
    }
    else {
        queue<ll> cyc_v;//vertices int the cycle;
        for (int i = 0;i < adj.size();i++)
            if (in_the_cycle[i])cyc_v.push(i);
        //bfs to find all the path reachable from the negative cycle vertices ;
        vector<ll> neg_path(adj.size(), 0);
        while (!cyc_v.empty()) {
            ll top = cyc_v.front();
            cyc_v.pop();

            for (ll i = 0;i < adj[top].size();i++) {
                if (!neg_path[adj[top][i]]) {
                    cyc_v.push(adj[top][i]);
                    neg_path[adj[top][i]] = 1; //negative path is there ;
                }
            }
        }


        for (ll i = 0;i < adj.size();i++) {

            if (reach[i]) {
                //path is reachable
                if (neg_path[i] == 1) cout << "-" << "\n";
                else  cout << dist[i] << "\n";
            }
            else cout << "*" << "\n";  //path is non reachable
        }
    }
}

int main() {
    ll n, m;
    std::cin >> n >> m;
    vector<vector<ll> > adj(n, vector<ll>());
    vector<vector<ll> > cost(n, vector<ll>());
    for (ll i = 0; i < m; i++) {
        ll x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    ll s; cin >> s;
    s--;
    //std::cout <<
    shortestpath(adj, cost, s);
}
