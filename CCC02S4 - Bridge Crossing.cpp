#include <bits/stdc++.h>
using namespace std;

int min_group(vector<vector<int> > &dp, int layer, int group){
  int m=0;
  for (int i=0; i<group; i++){
    if (dp[layer][i]<dp[layer][m]){
      m=i;
    }
  }
  return m+1;
}

int min_ele(vector<vector<int> > &dp, int column, int group){
  int m=9999999;
  if (column<0){
    return 0;
  }
  for (int i=0; i<group; i++){
    if (dp[column][i]<m){
      m=dp[column][i];
    }
  }
  return m;
}

int max_ele(int times[], int start, int ending)
{
  int m=0;
  for (int i=start; i<=ending; i++){
    if (times[i]>m){
      m=times[i];
    }
  }
  return m;
}

int main()
{
  int group, q, tim, layer, groupnum;
  cin>>group>>q;
  int times[q];
  string names[q], n;
  vector<int> group_reverse;
  vector<vector<int> >dp (q);
  vector<vector<string> >groupings (q);
  for (int i=0; i<q; i++){
    cin>>n>>tim;
    names[i]=n;
    times[i]=tim;
  }
  for (int i=0; i<group; i++){
    dp[0].push_back(times[0]);
  }
  for (int i=1; i<q; i++){
    for (int x=0; x<group; x++){
      dp[i].push_back(max_ele(times, i-x, i) + min_ele(dp, i-x-1, group));
    }
  }
  cout<<"Total Time: "<<min_ele(dp, q-1, group)<<endl;
  layer=q-1;
  do {
    groupnum=min_group(dp, layer, group);
    group_reverse.push_back(groupnum);
    layer-=groupnum;
  } while (layer>=0);
  int count=0;
  for (int i=group_reverse.size()-1; i>=0; i--){
    for (int x=0; x<group_reverse[i]; x++){
      cout<<names[count];
      count++;
      if (x<group_reverse[i]-1){
        cout<<" ";
      }
    }
    if (i>0){
      cout<<endl;
    }
  }
}
