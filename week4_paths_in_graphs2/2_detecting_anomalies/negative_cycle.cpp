#include <iostream>
#include <vector>

using namespace  std;
#define INF 10000
int negative_cycle(vector<vector<int> >& adj, vector<vector<int> >& cost) {
    //write your code here
      //bellman ford algo;
    std::vector<int> dist(adj.size(), INF);
    dist[0] = 0;
    int n = adj.size();
    bool cycle = true;
    while (n-- != 0) {
        bool relax = false;
     
        for (int i = 0;i < adj.size();i++) {
           // cout << " i is : " << i << '\n';
            for (int j = 0;j < adj[i].size();j++) {
                int v = adj[i][j];
               // cout << " v is :" << v+1 << '\n';
                if (dist[v] > (dist[i] + cost[i][j])) {
                  //  cout << "relax of : " << v+1 << "  dist is : " << dist[v] << "   ";
                    dist[v] = dist[i] + cost[i][j];  //relaxation;
                    relax = true;
                  //  cout <<"   after   dist is : " << dist[v] << "   \n";
                }
            }
        }
       
       
             if (relax == false) { cycle = false; break; }
    }
    if (cycle == false) return 0;

    return 1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    std::cout << negative_cycle(adj, cost);
}
