#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int friends, seperation;
  string a, b, des, pre;
  bool done= false;
  cin >> friends;
  string connections[friends][2];
  for (int i=0; i<friends; i++){
    cin >> a >> b;
    connections[i][0] = a;
    connections[i][1] = b;
  }
  while (true){
    seperation =-1;
    cin >> a >> b;
    pre= a, des = b;
    if (a=="0" and b=="0"){
      break;
    }
    for (int j=0; j<friends; j++){
      for (int i=0; i<friends; i++){
        if (connections[i][0] == a){
          a = connections[i][1];
          seperation++;
          if (a == des){
            cout<<"Yes "<<seperation<<endl;
            done=true;
            break;
          }
        }
        pre = a;
      }

      if (a == pre){
        cout<<"No"<<endl;
        break;
      }
      else if (done){
        break;
      }
    }
  }
  return 0;
}
