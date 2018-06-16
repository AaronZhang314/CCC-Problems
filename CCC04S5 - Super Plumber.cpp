#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int rows, cols, num, down, left, up;
  while (true){
    cin>>rows>>cols;
    if (rows==0 and cols==0){
      break;
    }
    vector<int> other(cols, -99999);
    vector<vector<int> >dpup (rows, other);
    vector<vector<int> >dpdown (rows, other);
    vector<vector<int> >dp (rows, other);
    string text[rows], thing;
    for (int i=0; i<rows; i++){
      cin>>thing;
      text[i]=thing;
    }
    for (int j=0; j<cols; j++){
      for (int i=rows-1; i>=0; i--){
        if (j>0){
          if (i<rows-1){
            if (text[i][j] == '.'){
              dpup[i][j] = max(dp[i][j-1], dpup[i+1][j]);
            }
            else if(text[i][j]=='*'){
              dpup[i][j] = -9999;
            }
            else{
              dpup[i][j] = int(text[i][j])-48 + max(dpup[i+1][j], dp[i][j-1]);
            }
          }
          else {
            if (text[i][j] == '.'){
              dpup[i][j] = dp[i][j-1];
            }
            else if(text[i][j]=='*'){
              dpup[i][j] = -9999;
            }
            else{
              dpup[i][j] = int(text[i][j])-48 +  dp[i][j-1];
            }
          }
        }
        else {
          if (i<rows-1){
            if (text[i][j] == '.'){
              dpup[i][j] =  dpup[i+1][j];
            }
            else if(text[i][j]=='*'){
              dpup[i][j] = -9999;
            }
            else{
              dpup[i][j] = int(text[i][j])-48 + dpup[i+1][j];
            }
          }
          else {
            if (text[i][j] == '.'){
              dpup[i][j] = 0;
            }
            else{
              dpup[i][j] = int(text[i][j])-48;
            }
          }
        }
      }
      for (int i=0; i<rows; i++){
        if (j>0){
          if (i>0){
            if (text[i][j] == '.'){
              dpdown[i][j] = max(dp[i][j-1], dpdown[i-1][j]);
            }
            else if(text[i][j]=='*'){
              dpdown[i][j] = -9999;
            }
            else{
              dpdown[i][j] = int(text[i][j])-48 + max(dpdown[i-1][j], dp[i][j-1]);
            }
          }
          else {
            if (text[i][j] == '.'){
              dpdown[i][j] = dp[i][j-1];
            }
            else if(text[i][j]=='*'){
              dpdown[i][j] = -9999;
            }
            else{
              dpdown[i][j] = int(text[i][j])-48 +  dp[i][j-1];
            }
          }
        }
        else {
          dpdown[i][j] = -1;
        }
      }

      for (int i=0; i<rows; i++){
        dp[i][j]=max(dpup[i][j], dpdown[i][j]);
      }
    }
    cout<<dp[rows-1][cols-1]<<endl;
  }
}
