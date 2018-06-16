#include <iostream>
using namespace std;

void recurse (int n, int k, string num, int end, int index)
{
  string str = num.substr(n-k, n-1);
  bool done = false;
  for (int i=k-1; i>=0; i--){
    if (str[i] == '1'){
      done = true;
      end = i+n-k-1;
    }
    else {
      done = false;
      break;
    }
  }
  if (done){
    cout<<num<<endl;
  }


  else {
    if (index+1 <= end){
      cout<<num<<endl;
      num[index] = '0';
      num[index+1] = '1';
      recurse (n, k, num, end, index+1);
    }
    else {
      cout<<num<<endl;
      for (int i=end; i>=0; i--){
        if (num[i] == '1'){
          num[i] = '0';
          for (int x=0; x<n-end; x++){
            num[i+x+1] = '1';
            index = i+x+1;
          }
          break;
        }
      }
      for (int i=index+1; i<n; i++){
        num[i] = '0';
      }
      recurse(n, k, num, n-1, index);
    }
  }
}


int main()
{
  int t, n, k;
  string num = "";
  cin >> t;
  for (int i=0; i<t; i++){
    num = "";
    cin>>n>>k;
    for (int x=0; x<k; x++){
      num += "1";
    }
    for (int x=0; x<n-k; x++){
      num += "0";
    }
    cout<<"The bit patterns are\n";
    if (num.length()==1 or k == 0 or n == k){
      cout<<num<<endl;
    }
    else {
      recurse(n, k, num, n-1, k-1);
    }
    cout<<endl;
  }
}
