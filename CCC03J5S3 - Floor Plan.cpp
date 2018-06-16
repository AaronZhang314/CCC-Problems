#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int floodfill(int x, int y, int &space, vector<vector<char> > &floor, int col, int row)
{
  if (floor[x][y]=='.'){
    floor[x][y]='I';
    space++;
    if (x<row-1){
      floodfill(x+1, y, space, floor, col, row);
    }
    if (x>0){
      floodfill(x-1, y, space, floor, col, row);
    }
    if (y>0){
      floodfill(x, y-1, space, floor, col, row);
    }
    if (y<col-1){
      floodfill(x, y+1, space, floor, col, row);
    }
  }
  return space;
}

int main()
{
  int tiles, rows, columns, space=0, x=0, y=0, room, count=0, total=0;
  cin>>tiles>>rows>>columns;
  vector<vector<char> >floor (rows);
  vector<int> spaces;
  string text;
  for (int i=0; i<rows; i++){
    cin>>text;
    for (int x=0; x<columns; x++){
      floor[i].push_back(text[x]);
    }
  }

  for (int i=0; i<columns*rows; i++){
    room=floodfill(x, y, space, floor, columns, rows);
    space=0;
    if (room>0){
      spaces.push_back(room);
      total+=room;
    }
    if (x<rows-1){
      x++;
    }
    else{
      x=0;
      if (y==columns-1){
        break;
      }
      y++;
    }
  }
  sort(spaces.begin(), spaces.end());

  for (int i=spaces.size()-1; i>=0; i--){
    if (tiles<spaces[i]){
      break;
    }
    tiles-=spaces[i];
    count++;
  }
  if (count!=1){
    cout<<count<<" rooms, ";
  }
  else {
    cout<<count<<" room, ";
  }
  cout<<tiles<<" square metre(s) left over";

}
