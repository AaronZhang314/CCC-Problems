#include <iostream>
#include <vector>
using namespace std;

int recurse(int pies, int people, int min, vector<vector<vector<int> > > &c){
  if (c[pies-1][people-1][min-1]!=-1){
    return c[pies-1][people-1][min-1];
  }
  else if(people == 1){
    return 1;
  }
  else{
    int ways = 0;
    for(int i = min; i <= pies/people; i++){
      ways += recurse(pies-i, people-1, i, c);
    }
    c[pies-1][people-1][min-1]=ways;
    return ways;
  }
}

int main(){
  int people, pies;

  cin >> pies >> people;
  vector<int>a (250, -1);
  vector<vector<int> >b(250, a);
  vector<vector<vector<int> > > c (250, b);
  cout << recurse(pies, people, 1, c) << endl;
  return 0;
}
