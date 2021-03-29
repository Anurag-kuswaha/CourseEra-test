@

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartitefkidsjfkjsdf(vector<vector<int> >& adj) {
    //write your code here
   // std::vector<int> visited(adj.size(), -1);
    std::vector<int> color(adj.size(),-1);
   
    color[0] = 1;
    queue<int> q;
    q.push(0);
   // visited[0] = 1;
   
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        //std::cout << "top is  " << top << "\n ";
        for (int i = 0;i < adj[top].size();i++) {
            //std::cout << adj[top][i] << " ";
            if (color[adj[top][i]]==-1)
            {
               // std::cout << "not visited" << "\n";
                //visited[adj[top][i]] = 1;
                q.push(adj[top][i]);
                
                 color[adj[top][i]] = 1-color[top];
                
            }
            else if (color[top] == color[adj[top][i]]) {
                 return 0;
            }
        }
        if (q.empty() == 0) {
            for (int i = 0;i < color.size();i++) {
                if (color[i]==-1) { q.push(i);break; }
            }
        }

    }

    return 1;
}
int bipartite(vector<vector<int> > &adj) {
 
  int colorArr[adj.size()];
  for (int i = 0; i < adj.size(); ++i)
    colorArr[i] = -1;
  
 
  colorArr[0] = 1;
  
  
  queue<int> queue;
  queue.push(0);
  
 
  while(!queue.empty()) {

    int u = queue.front();
	queue.pop();
	   
   
    for(int i=0; i < adj[u].size(); ++i) {
      int v = adj[u][i];
	 
      if (colorArr[v] == -1) {
       
        colorArr[v] = 1- colorArr[u];
		queue.push(v);
	  }
	  
      
      else if (colorArr[v] == colorArr[u])
        return 0;
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
