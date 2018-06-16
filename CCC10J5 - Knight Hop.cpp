#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
  int x, y, x2, y2;
  cin>>x>>y>>x2>>y2;
  int adj[64][64];
  for (int i=0; i<64; i++){
    adj[i][i]=1;
    for (int x=0; x<64; x++){
      adj[i][x]=0;
      if (i<48){
        if (i%8>0){
          adj[i][i+15] = 1;
        }
        if (i%8<7){
          adj[i][i+17] = 1;
        }
      }
      if (i%8>1){
        if (i<56){
          adj[i][i+6] = 1;
        }
        if (i>7){
          adj[i][i-10] = 1;
        }
      }
      if (i>15){
        if (i%8>0){
          adj[i][i-17] = 1;
        }
        if (i%8<7){
          adj[i][i-15] = 1;
        }
      }
      if (i%8<6){
        if (i<56){
          adj[i][i+10] = 1;
        }
        if (i>7){
          adj[i][i-6] = 1;
        }
      }
    }
  }

  queue<int> q;
  vector<int> path (64, -1);
  int node=(x-1)+((y-1)*8);
  int end=(x2-1)+((y2-1)*8);
  if (node==end){
    cout<<0;
  }
  else{
    path[node]=0;
    while (true){
      for (int i=0; i<64; i++){
        if (adj[node][i]==1 and path[i]==-1){
          q.push(i);
          path[i]=path[node]+1;
        }
      }
      node=q.front();
      if (node==end){
        break;
      }
      q.pop();
    }
    cout<<path[end];
  }
}
