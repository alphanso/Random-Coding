//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// light.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// light.cpp is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//==============================================================================

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
#include <cassert>
 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define PI 3.14159265

class light {
public :
  double S;
  double E;
  double X;
  double Y;
  double T;

  light(){};
  light(double X, double Y, double Z)
  {
    this->T = tan(Z*PI/180);
    this->X = X;
    this->Y = Y;
    double xi = (2.000000*T)*Y; 
    S = X - xi;
    E = X + xi;
  }

  void setV(double X, double Y, double Z)
  {
    this->T = tan(Z*PI/180);
    this->X = X;
    this->Y = Y;
    double xi = T*Y; 
    S = X - xi;
    E = X + xi;
  }
  
  void print()
  {
    cout << T << " " << Y << " " << S << " " << E << endl;
  }  
};
    
bool contained(light a, light b)
{
  if(a.S <= b.S && b.E <= a.E && b.Y <= a.Y) return true;
  else return false;
}
  
bool operator < (light a, light b)
{
  return a.S < b.S;
}

int main()
{
  int N;
  double L, R;
  double X, Y, Z;
  scanf("%d %lf %lf", &N, &L, &R);
  
  light l[N];
  FOR(i, 0, N)
    {
      scanf("%lf %lf %lf", &X, &Y, &Z);
      l[i].setV(X, Y, Z);
    }

  sort(l, l + N);
  // FOR(i, 0, N)
  //   l[i].print();

  int i, j;
  for(i = 0; i < N; i++)
    if(l[i].E <= L) continue;
    else break;
  // cout << l[i].S << " " << L << endl;
  assert(l[i].S < L);
  double base, height;
  
  if(l[i].X > L) 
    {
      base = L - l[i].S;
      height = base / l[i].T;
    }
  else if(l[i+1].S > L)
    {
      height = l[i].X;
    }
  else
    {
      double h1, h2;
      base = l[i].E - L;
      h1 = base / l[i].T;
      base = L - l[i+1].S;
      h2 = base / l[i+1].T;
      if(h2 > h1) {height = h2; i++;}
      else height = l[i].X;
    }

  for(; i < N-1; i++)
    {
      if(l[i].E > R) break;
      base = l[i].E - l[i+1].S;
      height = min(height, base/(l[i].T + l[i+1].T));
    }

  if(l[i].X < R) 
    {
      if(i == N - 1)
	{
	  base = l[i].E - R;
	  height = min(height, base / l[i].T);
	}
      else if(l[i+1].S > R)
	{
	  base = l[i].E - R;
	  height = min(height, base / l[i].T);
	}
      else
	{
	  double h1, h2, h3;
	  base = l[i].E - R;
	  h1 = base / l[i].T;
	  base = R - l[i+1].S;
	  h2 = base / l[i+1].T;
	  if(h1 > h2) height = min(height, h1);
	  else 
	    {
	      base = l[i].E - l[i+1].S;
	      h3 = base / (l[i].T + l[i+1].T);
	      height = min(height, h3);
	    }
	}
    }
  printf("%0.6lf\n", height);
  return 0;
}
  
  
