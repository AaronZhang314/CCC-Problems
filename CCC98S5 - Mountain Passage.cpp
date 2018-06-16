#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
  int trips, n, num;
  cin >> trips;
  for (int z=0; z<trips; z++){
    cin >> n;
    bool cannot = false;
    vector<int> grid (n*n, 0);
    vector<vector<int> > adj(n*n, grid);
    for (int i=0; i<n*n; i++){
      cin >> num;
      grid[i] = num;
    }

    for (int i=0; i<n*n; i++){
      if (i >= n){
        if (max(grid[i], grid[i-n]) - min(grid[i], grid[i-n]) <= 2){
          adj[i][i-n] = 1;
        }
      }
      if (i%n > 0){
        if (max(grid[i], grid[i-1]) - min(grid[i], grid[i-1]) <= 2){
          adj[i][i-1] = 1;
        }
      }
      if (i%n < n-1){
        if (max(grid[i], grid[i+1]) - min(grid[i], grid[i+1]) <= 2){
          adj[i][i+1] = 1;
        }
      }
      if (i<n*(n-1)){
        if (max(grid[i], grid[i+n]) - min(grid[i], grid[i+n]) <= 2){
          adj[i][i+n] = 1;
        }
      }
    }

    queue<int> q;
    int node = 0, des = n*n-1;
    vector<int> path(n*n, -1);
    path[0] = 0;
    while (true){
      for (int i=0; i<n*n; i++){
        if (adj[node][i] == 1 and path[i] == -1){
          q.push(i);
          path[i] = path[node];
          if (grid[i]>grid[0] or grid[node]>grid[0]){
            path[i]++;
          }
        }
      }
      node = q.front();

      if (node == des){
        break;
      }
      if (q.empty()){
        cannot = true;
        break;
      }
      q.pop();
    }
    q=queue<int> ();
    if (cannot){
      cout<<"CANNOT MAKE THE TRIP\n\n";
    }
    else{
      cout<<path[des]<<endl<<endl;
    }
  }
}
