#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
  int r, c, t, tick=0;
  string inter;
  cin>>t;
  for (int z=0; z<t; z++){
    cin>>r>>c;
    vector<int> other (c*r, 0);
    vector<vector<int> >adj (c*r, other);
    vector <char> inters (c*r, ' ');
    tick=0;
    for (int i=0; i<r; i++){
      cin>>inter;
      for (int x=0; x<c; x++){
        inters[tick]=inter[x];
        tick++;
      }
    }
    for (int i=0; i<r*c; i++){
      if (i>=c){
        if ((inters[i]=='+' or inters[i]=='|') and inters[i-c]!='*'){
          adj[i][i-c]=1;
        }
      }
      if (i%c>0){
        if ((inters[i]=='+' or inters[i]=='-') and inters[i-1]!='*'){
          adj[i][i-1]=1;
        }
      }
      if (i<r*c-c){
        if ((inters[i]=='+' or inters[i]=='|' )and inters[i+c]!='*'){
          adj[i][i+c]=1;
        }
      }
      if (i%c<c-1){
        if ((inters[i]=='+' or inters[i]=='-') and inters[i+1]!='*'){
          adj[i][i+1]=1;
        }
      }
    }
    queue<int> q;
    vector<int> path (r*c, -1);
    int node=0, des=r*c-1;
    if (node==des){
      cout<<1<<endl;
    }
    else{
      path[node]=1;
      while (true){
        for (int i=0; i<r*c; i++){
          if (adj[node][i]==1 and path[i]==-1){
            q.push(i);
            path[i]=path[node]+1;
          }
        }
        node=q.front();
        if (q.empty() or node==des){
          break;
        }
        q.pop();

      }
      cout<<path[des]<<endl;
    }
    q=queue<int> ();
  }
  return 0;
}
