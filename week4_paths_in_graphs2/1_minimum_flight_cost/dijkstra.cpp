#include <iostream>
#include <vector>
#include <queue>
#define INF INT32_MAX
#define ll long long

using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;
class comp {
public:
    bool operator()(const pair<ll, ll>& a,const pair<ll, ll>& b) {
        return a.first < b.first;
    }
};

long long distance(vector<vector<ll> >& adj, vector<vector<ll> >& cost, ll s, ll t) {
    //write your code her
    vector<long long> dist(adj.size(), INF);
    dist[s] = 0;
    priority_queue< pair<ll,ll>,vector<pair<ll,ll>>,  greater<pair<int,int>> > pq;

    pq.push({ 0,s }); //just put the soure vertex with distance=0;

    while (!pq.empty()) {
        pair<ll, ll> temp = pq.top();
        pq.pop();
        ll d = temp.first; ll v = temp.second;
        for (ll i = 0;i < adj[v].size();i++) {
            ll u = adj[v][i];
            ll cost_ = cost[v][i];
            if (dist[u] > dist[v] + cost_) {
                dist[u] = dist[v] + cost_;
                
                
                pq.push({ dist[u], u });
                
            }
        }
    }
    if (dist[t] != INF) return dist[t];
    return -1;
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
    ll s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, cost, s, t);
}
