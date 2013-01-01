//      choose.cpp
//      
//      Copyright 2011 Rishabh Singhal <rishabh@cse.iitb.ac.in>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      
//      

#include <iostream>

using namespace std;

#ifndef _CHOOSE_
#define _CHOOSE_

typedef long long ll;

ll mem[5001] = {0};

void init(ll mod)
{
  mem[0] = 1;
  mem[1] = 1;
  for(int i = 2; i < 5001; i++)
    {
      mem[i] = (mem[i-1] * i) % mod;
      //cout<<mem[i]<<endl;
    }
}

ll modPow(ll a, ll x, ll p)
{
  ll res = 1;
  while(x > 0)
    {
      if(x % 2) res = (res * a) % p;
      a = (a * a) % p;
      x /= 2;
    }
  return res;
}

ll modInverse(ll a, ll p)
{
  return modPow(a, p-2, p);
}

int choose(int n, int k, ll p)
{
  ll numerator = mem[n];
  ll denominator_k = modInverse(mem[k],p);
  ll denominator = (denominator_k * modInverse(mem[n-k],p)) % p ;

  return ((numerator * denominator) % p);
}
#endif
