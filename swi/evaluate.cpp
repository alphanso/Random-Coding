//==============================================================================
// Copyright (C) 2012 Rishabh Singhal <rinkusinghal05@gmail.com>

// evaluate.cpp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// evaluate.cpp is distributed in the hope that it will be useful,
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

#define DOUBLE_MAX 100000000000000

int main()
{
  double current_price, target_price;
  int buy_or_sell; //buy -> 1 and sell -> 0
  int call_or_put; //call -> 1 and put -> 0
  double strike_price, premium;
  cin >> current_price >> buy_or_sell;
  cin >> call_or_put >> strike_price >> premium;
  cin >> target_price;
  double profit, risk;
  if(buy_or_sell)
    {
      if(call_or_put)
	{
	  risk = premium * 100;
	  if(target_price < strike_price) profit = -risk;
	  else profit = (target_price - strike_price - premium)*100;
	}
      else
	{
	  risk = premium * 100;
	  if(target_price > strike_price) profit = -risk;
	  else profit = (strike_price - target_price - premium) * 100;
	}
    }
  else
    {
      if(call_or_put)
	{
	  risk = DOUBLE_MAX;
	  if(target_price < strike_price) profit = premium*100;
	  else profit = (-target_price + strike_price + premium)*100;
	}
      else
	{
	  risk = DOUBLE_MAX;
	  if(target_price > strike_price) profit = premium*100;
	  else profit = (-strike_price + target_price + premium) * 100;
	}
    }
  cout << profit << " ";
  if(risk == DOUBLE_MAX) cout << "UNLIMITED" << endl;
  else cout << risk << endl;
  return 0;
}  
