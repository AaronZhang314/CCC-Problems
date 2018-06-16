#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, num, largest=0, a, b;
  vector<int> readings (1000, 0);
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> num;
    readings[num]++;
  }
  for (int i=0; i<readings.size(); i++){
    if (readings[i]>=largest){
      a = i;
      largest = readings[i];
    }
  }
  largest = 0;
  b = a;
  for (int i=readings.size(); i>=0; i--){
    if (readings[i]>largest and i!=a){
      b = i;
      largest = readings[i];
    }
    else if (readings[i]==largest and i!=a and max(a, i) - min(a, i) > max(a, b) - min(a, b)){
      b = i;
      largest = readings[i];
    }
  }
  cout<<max(a, b) - min(a, b);
}
