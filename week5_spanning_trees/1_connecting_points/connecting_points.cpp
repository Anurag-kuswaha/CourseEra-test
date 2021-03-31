#include <iostream>
#include <vector>
#include<queue>
#include<set>

#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
#define INF 1e12
#define ll long long

double minimum_distance(vector<int> x, vector<int> y) {
    double result = 0.000000;
    //write your code here
    int n = x.size();
    vector<vector<pair<int, double>>> adj(n);
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (i == j) continue;
            double x_ = abs(x[i] - x[j]);
            double y_ = abs(y[i] - y[j]);
            double dist = pow((x_ * x_ + y_ * y_), 0.5);
            adj[i].push_back({ j,dist });

        }
    }
    /*int j=0;
    for(auto i: adj){
      cout<<j<<"  : ";
      for(auto it: i){
        cout<<it.first<<" : "<<it.second<<" || " ;
      }
      j++;
      cout<<"\n";
    } */
    //prims alogorithm;
    //1-> create priority queue as ditacne adn vertices format;
    //make diostance infinity except one verices dist as 0;
    // extract the minumum from the priority queue and run over all the edges
    // and update the new distance of the vertices as the weight of the edges ;
    // again extract the min val and repeat the step until the pq is not empty;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    std::vector<double> dist(n, INF);
    std::vector<int> parent(n);
    dist[0] = 0;
   // for (int i = 0;i < n;i++) {
        pq.push({ dist[0],0 });
    //}
    vector<int> vis(n, 0);
    while (!pq.empty()) {
        pair<double, int> top = pq.top();
        pq.pop();
        int v = top.second;
        if (vis[v] == 1) continue;
        for (int i = 0;i < adj[v].size();i++) {
            auto pr = adj[v][i];
            int u = pr.first; double d = pr.second;
            if (! vis[u] && dist[u] > d) {
                dist[u] = d;
                parent[u] = v;
                pq.push({ d,u });
            }
        }
        vis[v] = 1;
    }
    // vector<int> vis(n,0);
    for (int i = 0;i < n;i++) {
       // cout << i << "  : " << dist[i] << "  parent is" << parent[i] << "\n";
        // if(!vis[i]){
         result += dist[i];
        // vis[i]=1; vis[parent[i]]=1;
    }

    return result;
}
int main() {
    size_t n;
    std::cin >> n;
    vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
