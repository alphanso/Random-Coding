#include<iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <utility>
using namespace std;

/* Head ends here */
double rdistance(int x1, int y1, int x2, int y2)
{
  return (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

void next_move(char player, int *dr,int* cop1, int* cop2, int* cop3) {
  srand(time(NULL));
  if(player == 'R')
    {
      vector< pair<int, int> > moves, dmoves;
      double mdist = -100000;
      int x = dr[0], y = dr[1];
      int c1, c2;
      if(x <= 9) c1 = 10;
      else c1 = 9;
      if(y <= 9) c2 = 10;
      else c2 = 9;
      for(int i = -1; i < 2; i++)
      	{
      	  if(dr[0] + i > 19 || dr[0] + i < 0) continue;
      	  for(int j = -1; j < 2; j++)
      	    {
      	      if(dr[1] + j > 19 || dr[1] + j < 0) continue;
      	      double dist1 =  rdistance(x+i, y+j, cop1[0], cop1[1]);
	      double dist2 =  rdistance(x+i, y+j, cop2[0], cop2[1]);
	      double dist3 =  rdistance(x+i, y+j, cop3[0], cop3[1]);
	      if(dist1 <= 1 || dist2 <= 1 || dist3 <= 1)
		{
		  dmoves.push_back(make_pair(x+i, y+j));
		  continue;
		}
	      // cout << dist << " " << x + i << " " << y + j << endl;
	      double dist = dist1 + dist2 + dist3 - 3 * rdistance(x+i, y+j, c1, c2);
      	      if(dist > mdist) 
      		{
      		  mdist = dist;
      		  moves.clear();
      		  moves.push_back(make_pair(x+i, y+j));
      		}
      	      else if (dist == mdist)
      		moves.push_back(make_pair(x+i, y+j));
      	    }
      	}
      
      int sz;
      if(moves.size() != 0) {
	sz = rand() % (moves.size());
	cout << moves[sz].first << " " << moves[sz].second << endl;
      }
      else
	{
	  sz = rand() % (dmoves.size());
	  cout << dmoves[sz].first << " " << dmoves[sz].second << endl;
	} 
    }
  else 
    {
      int dist1 = abs(cop1[0] - dr[0]);
      int dist2 = abs(cop2[0] - dr[0]);
      int dist3 = abs(cop3[0] - dr[0]);
      int disty = abs(cop1[1] - dr[1]);
      if(dist1 == 0 || dist2 == 0 || dist3 == 0) 
	{
	  int pdist = abs(cop1[1] + 1 - dr[1]);
	  int ndist = abs(cop1[1] - 1 - dr[1]);
	  if(pdist < ndist)
	    {
	      cout << cop1[0] << " " << cop1[1]+1 << " ";
	      cout << cop2[0] << " " << cop2[1]+1 << " ";
	      cout << cop3[0] << " " << cop3[1]+1 << endl;
	    }
	  else 
	    {
	      cout << cop1[0] << " " << cop1[1]-1 << " ";
	      cout << cop2[0] << " " << cop2[1]-1 << " ";
	      cout << cop3[0] << " " << cop3[1]-1 << endl;
	    } 
	}
      else if(dist1 == 1 && dist2 == 1 && dist3 == 1)
	{
	  cout << cop1[0] << " " << cop1[1] << " ";
	  cout << cop2[0]+1 << " " << cop2[1] << " ";
	  cout << cop3[0]-1 << " " << cop3[1] << endl;
	}
      else
	{
	  int pdist = abs(cop1[0] - dr[0] + 1) + abs(cop3[0] - dr[0] + 1) + abs(cop2[0] - dr[0] + 1);
	  int ndist = abs(cop1[0] - dr[0] - 1) + abs(cop3[0] - dr[0] - 1) + abs(cop2[0] - dr[0] - 1);
	  if(pdist < ndist)
	    {
	      cout << cop1[0]+1 << " " << cop1[1] << " ";
	      cout << cop2[0]+1 << " " << cop2[1] << " ";
	      cout << cop3[0]+1 << " " << cop3[1] << endl;
	    }
	  else
	    {
	      cout << cop1[0]-1 << " " << cop1[1] << " ";
	      cout << cop2[0]-1 << " " << cop2[1] << " ";
	      cout << cop3[0]-1 << " " << cop3[1] << endl;	      
	    }
	}
    }
  return;	
}

int main() {
    int dr[2],cop1[2],cop2[2],cop3[2];
    char player;
    cin>>player;
    cin>>dr[0]>>dr[1];
    cin>>cop1[0]>>cop1[1]>>cop2[0]>>cop2[1]>>cop3[0]>>cop3[1];
    next_move(player,dr,cop1,cop2,cop3);
}
