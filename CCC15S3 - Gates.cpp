#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int G, P, dock, total=0, firsthighindex;
  cin>>G>>P;
  vector <int> openindex;
  vector<int>::iterator firsthigh;
  for (int i=0; i<G; i++){
    openindex.push_back(i);
  }

  for (int i=0; i<P; i++){
    cin>>dock;
    firsthigh= lower_bound(openindex.begin(), openindex.end(), dock);
    if (int(firsthigh- openindex.begin())!=0){
      firsthighindex=int(firsthigh- openindex.begin())-1;
      openindex.erase(openindex.begin()+firsthighindex);
      total++;
    }
    else{
      break;
      }
  }
  cout<<total;
  return 0;
}
