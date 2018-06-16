#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, num, previous, length;
  bool done;
  while (true){
    cin >> n;
    if (n == 0){
      break;
    }
    else if (n == 1 or n == 2){
      for (int i=0; i<n; i++){
        cin >> num;
      }
      cout << n-1 << endl;
    }
    else{
      vector<int> differences (n-1, 0);
      cin >> previous;
      for (int i=0; i<n-1; i++){
        cin >> num;
        differences[i] = num - previous;
        previous = num;
      }
      for (int i=1; i<n-1; i++){
        done = false;
        if (differences.at(i) == differences.at(0)){
          done = true;
          length = i;
          for (int j=1; j<n-2-i; j++){
            if (differences.at(j) != differences.at(j+i)){
              done = false;
              break;
            }
          }
          if (done){
            break;
          }
        }
      }
      if (not done){
        cout << n-1 << endl;
      }
      else{
        cout << length <<endl;
      }
    }
  }
}
