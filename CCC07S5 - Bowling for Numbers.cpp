#include <iostream>
using namespace std;

int main()
{
  int tests, num, balls, adj, val, score;
  cin>>tests;
  for (int z=0; z<tests; z++){
    cin>>num>>balls>>adj;
    int pins[num], dp[balls+1][num];
    for (int i=0; i<balls; i++){
      for (int j=0; j<num; j++){
        dp[i][j] = 0;
      }
    }

    for (int i=0; i<num; i++){
      cin>>val;
      pins[i] = val;
    }

    for (int x=1; x<=balls; x++){
      dp[x][0] = pins[0];
      for (int i=1; i<num; i++){
        if (i<x*adj){
          dp[x][i] = pins[i]+dp[x][i-1];
        }
        else{
          score = 0;
          for (int j=0; j<adj; j++){
            score+=pins[i-j];
          }
          dp[x][i]=max(score+dp[x-1][i-adj], dp[x][i-1]);
        }
      }
    }
    cout<<dp[balls][num-1]<<endl;
  }
}
