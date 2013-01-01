#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
using namespace std;
#define INRANGE(i,a,b) (i>=a && i<b)
int co_ord_distance(int a, int b, int c, int d) {
  return abs(c-a)+abs(d-b);
}
int main() {
  srand(time(NULL));
  char player;
  cin>>player;
  int rob[2];
  int pol[6];
  cin>>rob[0];
  cin>>rob[1];
  for(int i=0;i<6;i++) cin>>pol[i];
  vector< pair < int , int > > moves;
  if (player == 'R') {
    moves.push_back(make_pair(rob[0],rob[1]));
    int dist1 = co_ord_distance(rob[0],rob[1],pol[0],pol[1]);
    int dist2 = co_ord_distance(rob[0],rob[1],pol[2],pol[3]);
    int dist3 = co_ord_distance(rob[0],rob[1],pol[4],pol[5]);
    int dist = dist1 + dist2 + dist3;
    for(int i=-1;i<2;i++) {
      for(int j=-1;j<2;j++) {
	int x = rob[0]+i;
	int y = rob[1]+j;
	if(INRANGE(x,0,20) && INRANGE(y,0,20)) {
	  int temp = co_ord_distance(x,y,pol[0],pol[1]) + co_ord_distance(x,y,pol[2],pol[3]) + co_ord_distance(x,y,pol[4],pol[5]);
	  if (temp <= dist) {
	    moves.push_back(make_pair(x,y));
	  }
	}
      }
    }
    int siz = rand()%moves.size();
    cout<<moves[siz].first<<" "<<moves[siz].second;
    return 0;
  } else {
    vector< pair < int, int > > move1;
    vector< pair < int, int > > move2;
    vector< pair < int, int > > move3;
    move1.push_back(make_pair(pol[0],pol[1]));
    move2.push_back(make_pair(pol[2],pol[3]));
    move3.push_back(make_pair(pol[4],pol[5]));
    int dist1 = co_ord_distance(rob[0],rob[1],pol[0],pol[1]);
    int dist2 = co_ord_distance(rob[0],rob[1],pol[2],pol[3]);
    int dist3 = co_ord_distance(rob[0],rob[1],pol[4],pol[5]);
    for(int i=-1;i<2;i++) {
      for(int j=-1;j<2;j++) {
	if(i!=0 && j!=0) continue;
	int a = pol[0]+i;
	int b = pol[1]+j;
	int c = pol[2]+i;
	int d = pol[3]+j;
	int e = pol[4]+i;
	int f = pol[5]+j;
	if (INRANGE(a,0,20) && INRANGE(b,0,20)) {
	  int temp = co_ord_distance(a,b,rob[0],rob[1]);
	  if(temp<dist1) move1.push_back(make_pair(a,b));
	}
	if (INRANGE(c,0,20) && INRANGE(d,0,20)) {
	  int temp = co_ord_distance(c,d,rob[0],rob[1]);
	  if(temp<dist2) move2.push_back(make_pair(c,d));
	}
	if (INRANGE(e,0,20) && INRANGE(f,0,20)) {
	  int temp = co_ord_distance(e,f,rob[0],rob[1]);
	  if(temp<dist3) move3.push_back(make_pair(e,f));
	}
      }
    }
    int ran1 = rand()%move1.size();
    int ran2 = rand()%move2.size();
    int ran3 = rand()%move3.size();
    cout<<move1[ran1].first<<" "<<move1[ran1].second<<" "<<move2[ran2].first<<" "<<move2[ran2].second<<" "<<move3[ran3].first<<" "<<move3[ran3].second;
  }
  return 0;
}
