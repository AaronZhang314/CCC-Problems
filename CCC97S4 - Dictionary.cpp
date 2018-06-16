#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

int main()
{
  int t, count=1;
  string sent, word;
  vector<string>dict;
  map<string, int>index;
  cin>>t;
  cin.ignore();
  for (int i=0; i<t; i++){
    while (true){
      getline (cin, sent);
      stringstream ss (sent);
      if (sent.empty()){
        break;
      }
      else {
        while (ss>>word){
          if (find(dict.begin(), dict.end(), word) == dict.end()){
            dict.push_back(word);
            index[word]=count;
            count++;
            cout<<word<<" ";
          }
          else {
            cout<<index[word]<<" ";
          }
        }
        cout<<endl;
      }
    }
    count = 1;
    dict.clear();
    index.clear();
    cout<<endl;
  }
}
