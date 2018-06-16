#include <bits/stdc++.h>
using namespace std;

int main()
{
  int dis, club, size;
  cin>>dis>>club;
  int t[dis+1];
  for (int i=1; i<=dis; i++){
    t[i]=9999999;
  }
  t[0]=0;
  int j[club];
  for (int i=0; i<club; i++){
    cin>>size;
    j[i]=size;
  }

  for (int i=1; i<=dis; i++){
    for (int x=0; x<club; x++){
      if (j[x]<=i and t[i-j[x]]+1<t[i]){
        t[i]=t[i-j[x]]+1;
      }
    }
  }
  if (t[dis]<9999999){
    cout<<"Roberta wins in "<<t[dis]<<" strokes.";
  }
  else{
    cout<<"Roberta acknowledges defeat.";
  }

}
