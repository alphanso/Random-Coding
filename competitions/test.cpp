#include <iostream>
#include "choose.cpp"
using namespace std;

int main()
{
  ll mod = 1000000007;
  init(mod);
  for(int i=1;i<100;i++)
    {
    for(int j=0;j<=i;j++)
      cout<<choose(i,j,mod)<<"\t";
    cout<<endl;
    }
  return 0;
}
