#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, undefeated, oneloss=0, eliminated=0, round=0;
  cin>>N;
  bool lastround=false;
  for (int z=0; z<N; z++){
    cin>>undefeated;
    round=0;
    oneloss=0;
    eliminated=0;
    while (true){
      if (round==0){
        cout<<"Round "<<round<<": "<<undefeated<<" undefeated, "<<oneloss<<" one-loss, "<<eliminated<<" eliminated\n";
      }
      else{
        if (undefeated==1 and oneloss==0 and eliminated==0){
          break;
        }

        else if (undefeated==1 and oneloss%2==0){
          eliminated+=oneloss/2;
          oneloss-=oneloss/2;
        }
        else if (undefeated==1 and oneloss==1){
          undefeated=0;
          oneloss=2;
        }
        else{
          eliminated+=oneloss/2;
          oneloss-=oneloss/2;
          oneloss+=undefeated/2;
          undefeated-=undefeated/2;
        }



        cout<<"Round "<<round<<": "<<undefeated<<" undefeated, "<<oneloss<<" one-loss, "<<eliminated<<" eliminated\n";
        if (oneloss==1 and undefeated==0){
          break;
        }
      }
      round++;
    }
    cout<<"There are "<<round<<" rounds.\n";
  }
}
