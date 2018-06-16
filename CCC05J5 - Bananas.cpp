#include <bits/stdc++.h>
using namespace std;

bool monkey (string text){
  bool n=false, b=false, nb=false, s=false;
  int num;

  if (text=="A"){
    return true;
  }

  else {
     for (int i=0; i<text.length(); i++){
      if (text[i]=='B'){
        b=true;
        num=i;
        break;
      }

      else if (text[i]=='N'){
        n=true;
        num=i;
        break;
      }
    }

    if (b){
      string middle=text.substr(1, (text.length()-2));
      for (int i=text.length()-1; i>num; i--){
        if (text[i]=='S' and i==text.length()-1){
          for (int x=i; x>num; x--){
            if (text[x]=='S' and x<i){
              s=true;
            }
            else if (text[x]=='B'){
              if (text[x-1]!='N' or s){
                for (int z=x-1; z>num; z--){
                  if (text[z]=='B' and text[z-1]=='N'){
                    n=true;
                    num=z-1;
                    break;
                  }
                }
                if (n){
                  break;
                }
                //cout<<"Returned middle: "<<middle<<endl;
                return monkey(middle);
              }
              else {
                n=true;
                num=x-1;
                break;
              }
            }
          }
          if (n){
            break;
          }
          //cout<<"Returned middle: "<<middle<<endl;
          return monkey(middle);
        }
        else if (text[i]=='N'){
          n=true;
          nb=true;
          num=i;
          break;
        }
        else if (i==num+1){
          return false;
        }
      }
    }

    if (n){
      string left, right;
      if (nb){
        //cout<<"NB true\n";
        left=text.substr(0, num);
        right=text.substr(num+1, (text.length()-1));

      }
      else{
        //cout<<"N true\n";
        left=text.substr(0, num);
        right=text.substr(num+1, (text.length()-(num+1)));
      }
      //cout<<"Left: "<<left<<endl;
      //cout<<"Right: "<<right<<endl;
      if (monkey(left)==true and monkey(right)==true){
        return true;
      }
      else {
        return false;
      }
    }

    else {
      return false;
    }
  }
}

int main()
{
  string text;
  while (true){
    cin>>text;
    if (text=="X"){
      break;
    }
    else{
      if (monkey(text)){
        cout<<"YES\n";
      }
      else{
        cout<<"NO\n";
      }
    }
  }
}
