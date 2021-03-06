#include <iostream>
#include <vector>
#include <queue>
using std::vector;
using std::queue;

int bipartite(vector<vector<int> >& adj) {
          //write your code here
   // std::vector<int> visited(adj.size(), -1);
    std::vector<int> color(adj.size(),-1);
   
    queue<int> q;
   
   // visited[0] = 1;
    for (int j = 0;j < color.size();j++){
      
        if(color[j] ==-1){
             q.push(j);
            color[j] = 1;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
       // std::cout << "top is  " << top << "\n ";
        for (int i = 0;i < adj[top].size();i++) {
            //std::cout << adj[top][i] << " ";
            if (color[adj[top][i]]==-1)
            {
                //std::cout << "not visited" << "\n";
                //visited[adj[top][i]] = 1;
                q.push(adj[top][i]);
                
                 color[adj[top][i]] = 1-color[top];
                
            }
            else if (color[top] == color[adj[top][i]]) {
                 return 0;
            }
        }
       
        }

   }
    }

    return 1;
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
    std::cout << bipartite(adj);
}
