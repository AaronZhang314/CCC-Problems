#include <bits/stdc++.h>
using namespace std;

int main()
{
  int min, max, extra, stop;
  vector<int>::iterator low;
  vector<int>stops={0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
  cin>>min>>max>>extra;
  for (int i=0; i<extra; i++){
    cin>>stop;
    low=lower_bound (stops.begin(), stops.end(), stop);
    stops.insert(stops.begin()+(low-stops.begin()), stop);
  }
  int dp[stops.size()];
  for(int i=0; i<stops.size(); i++){
    dp[i]=0;
  }
  dp[0]=1;
  for (int i=0; i<stops.size(); i++){
    for (int x=i+1; x<stops.size(); x++){
      if (stops[x]-stops[i]>=min and stops[x]-stops[i]<=max){
        dp[x]+=dp[i];
      }
    }
  }
  cout<<dp[stops.size()-1];
}
