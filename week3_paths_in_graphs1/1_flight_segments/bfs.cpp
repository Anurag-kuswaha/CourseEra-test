#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> >& adj, int s, int t) {
    //write your code here
    queue<int> q;
    q.push(s);
    vector<int> visited(adj.size(), 0);
    vector<int> distance(adj.size(), 0);
    visited[s] = 1;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i = 0;i < adj[top].size();i++) {
            int c = adj[top][i];
            if (!visited[c]) {
                visited[c] = 1;
                q.push(c);
                distance[c] = distance[top] + 1;
            }
            if (visited[c] && c == t) return distance[c];
        }
    }
    return -1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, s, t);
}
