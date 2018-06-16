#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int points, a, b;
  cin>>points;
  vector< vector <int> >connections (points);
  while (true){
    cin>>a>>b;
    if (a==0 and b==0){
      break;
    }
    else {
      connections[a-1].push_back(b);
    }
  }
  int dp[points];
  dp[0]=1;
  for (int i=1; i<points; i++){
    dp[i]=0;
    for (int z=i-1; z>=0; z--){
      for (int x=0; x<connections[z].size(); x++){
        if (connections[z][x]==i+1){
          dp[i]+=dp[z];
        }
      }
    }
  }
  cout<<dp[points-1];
}
