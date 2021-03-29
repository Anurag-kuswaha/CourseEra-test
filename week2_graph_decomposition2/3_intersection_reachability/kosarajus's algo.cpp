// now.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<deque>
#include<stack>
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
void dfs_sink(vector<vector<int> >& adj, stack<int>& start, vector<int>& visited, int x, int& clock) {
    if (visited[x]) return;
   
    visited[x] = 1;
    int n = adj[x].size();
    for (int i = 0;i < n;i++) {
        if (!visited[adj[x][i]]) {
            dfs_sink(adj, start, visited, adj[x][i], clock);
        }
    }
    start.push(x);
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
    stack<int> start;
    int clock = 1;
    for (int i = 0;i < adj.size();i++) {
        if (!visited[i]) dfs_sink(adj, start, visited, i, clock);
    }
 
    for (int i = 0;i < n;i++) visited[i] = 0;
   while(!start.empty()) {
       int top = start.top();
       start.pop();
       // cout << "passing sink value of : " << top << "  ";
        if (!visited[top]) {
            //cout << "-- not visited" << "  dfs is running -> ";
            dfs(reverse_adj, visited, top);
            result++;
           // cout << "\n \n";
        }
       //  else {
            // cout << "--  visited" << "  ";
            // cout << "\n \n";
        //}
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
