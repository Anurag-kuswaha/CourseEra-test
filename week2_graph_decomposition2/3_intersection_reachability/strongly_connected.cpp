// now.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<deque>
#include<queue>
using namespace std;
// now.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
#include<deque>
#include<vector>
#include<queue>
using namespace std;
void dfs_sink(vector<vector<int> >& reverse_adj, vector<int>& sink, vector<int>& visited, int x, int& clock) {
    if (visited[x]) return;
    visited[x] = 1;
    int n = reverse_adj[x].size();
    for (int i = 0;i < n;i++) {
        if (!visited[reverse_adj[x][i]]) {
            dfs_sink(reverse_adj, sink, visited, reverse_adj[x][i], clock);
        }
    }
    sink.push_back(x);
    //cout << x+1 << " ";
    clock++;
}
void dfs(vector<vector<int> >& adj, vector<int>& visited, int x) {
    //cout << x << "  ";
    if (visited[x]) return;
    visited[x] = 1;
    int n = adj[x].size();
    for (int i = 0;i < n;i++) {
        if (!visited[adj[x][i]]) {
            dfs(adj, visited, adj[x][i]);
        }
    }
}
int number_of_strongly_connected_components(vector<vector<int> >& adj, vector<vector<int> >& reverse_adj) {
    int result = 0;
    //write your code here
    vector<int> visited(adj.size(), 0);
    int n = adj.size();
    vector<int> sink;
    int clock = 1;
    for (int i = 0;i < reverse_adj.size();i++) {
        if (!visited[i]) dfs_sink(reverse_adj, sink, visited, i, clock);
    }
    //sort(begin(sink), end(sink), [&]( pair<int,int>&a, pair<int,int>& b) {return a.first > b.first;});
    //sort(begin(sink), end(sink), [&](int a, int b) {return a > b;});
    //reverse(begin(sink),end(sink));
    for (int i = 0;i < n;i++) visited[i] = 0;
    for (int i = 0;i < n;i++) {
        //cout << "passing sink value of : " << sink[n - 1 - i] << "  ";
        if (!visited[sink[n - i - 1]]) {
            //cout << "-- not visited" << "  dfs is running -> ";
            dfs(adj, visited, sink[n - i - 1]);
            result++;
            //cout << "\n \n";
        }
        // else {
           //  cout << "--  visited" << "  ";
            // cout << "\n \n";
       //  }
    }

    return result;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > reverse_adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        reverse_adj[y - 1].push_back(x - 1);
    }
    std::cout << number_of_strongly_connected_components(adj, reverse_adj);
}
