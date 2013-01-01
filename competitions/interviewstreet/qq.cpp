#include <cstdio>
#include <cassert>
#include <iostream>
#include <cstring>
using namespace std;

class plane {
public:
  int x[4];
  int mod;
  plane()
  {
    memset(x, 0, sizeof(x));
    mod = 0;
  }
};

plane sum(plane a, plane b)
{
  plane ans;
  for(int i = 0; i < 4; i++)
    ans.x[i] = a.x[i] + b.x[i];
  return ans;
}

plane tree[131072 * 2];
    
void init(int node, int start, int end, int P[])
{
  if (start==end)
    {
      //cout << P[start] << endl;
      tree[node].x[P[start]]++;
    }
  else
    {
      int mid = (start + end) / 2;
      init(2 * node, start, mid, P);
      init(2 * node + 1, mid + 1, end, P);
      tree[node] = sum(tree[2 * node], tree[2 * node + 1]);
    }
}

void printp(int node)
{
  cout << tree[node].x[3] << " " << tree[node].x[2] << " ";
  cout << tree[node].x[0] << " " << tree[node].x[1] << "\t";
  cout << tree[node].mod << endl;
}

void print(int node, int start, int end)
{
  cout << tree[node].x[3] << " " << tree[node].x[2] << " ";
  cout << tree[node].x[0] << " " << tree[node].x[1] << "\t";
  cout << tree[node].mod << endl;
  if(start == end) return;
  int mid = (start + end) / 2;
  print(2 * node, start, mid);
  print(2 * node + 1, mid + 1, end);
}

plane query(int node, int start, int end, int i, int j, int pmode)
{
  plane id1,id2;
  tree[node].mod ^= pmode;
  if(pmode & 1)
    {
      swap(tree[node].x[0], tree[node].x[1]);
      swap(tree[node].x[2], tree[node].x[3]);
    }

  if(pmode & 2)
    {
      swap(tree[node].x[0], tree[node].x[2]);
      swap(tree[node].x[1], tree[node].x[3]);
    }

  if (i > end || j < start)
    return id1;

  if (start >= i && end <= j)
    {
      return tree[node];
    }

  int mid = (start + end) / 2;
  id1 = query(2 * node, start, mid, i, j, tree[node].mod);
  id2 = query(2 * node + 1, mid + 1, end, i, j, tree[node].mod);
  tree[node].mod = 0;
  return sum(id1, id2);
}

void mirror(int node, int start, int end, int i, int j, int pmod, int action)
{
  if(pmod & 1)
    {
      swap(tree[node].x[0], tree[node].x[1]);
      swap(tree[node].x[2], tree[node].x[3]);
    }
  
  if(pmod & 2)
    {
      swap(tree[node].x[0], tree[node].x[2]);
      swap(tree[node].x[1], tree[node].x[3]);
    }
  tree[node].mod ^= pmod;
  if(i > end || j < start)
    return ;
  
  if(i <= start && end <= j)
    {
      if(action & 1)
	{
	  //cout << "Y\n";
	  swap(tree[node].x[0], tree[node].x[1]);
	  swap(tree[node].x[2], tree[node].x[3]);
	}
      if(action & 2)
	{
	  //cout << "X\n";
	  swap(tree[node].x[0], tree[node].x[2]);
	  swap(tree[node].x[1], tree[node].x[3]);
	}
      tree[node].mod ^= action;
      return ;
    }
    
  int mid = (start + end) / 2;
  mirror(2 * node, start, mid, i, j, tree[node].mod, action);
  mirror(2 * node + 1, mid + 1, end, i, j, tree[node].mod, action);
  tree[node] = sum(tree[2 * node], tree[2 * node + 1]);
  
  return ;
}

int main()
{
  int N, Q;
  scanf("%d", &N);
  //cout << N << endl;
  int P[N + 1], x, y;
  for(int i = 1; i <= N; i++)
    {
      scanf("%d %d", &x, &y);
      if(x > 0 && y > 0) P[i] = 3; 
      else if(x > 0 && y < 0) P[i] = 1;
      else if(x < 0 && y > 0) P[i] = 2;
      else if(x < 0 && y < 0) P[i] = 0;
      else assert(false);
    }
    
  init(1, 1, N, P);
  // print(1, 1, N);
  scanf("%d", &Q);
  //cout << Q << endl;
  int i, j;
  char C;
  while(Q--)
    {
      cin >> C;
      //cout << C << endl;
      scanf("%d %d", &i, &j);
      if(C == 'C')
        {
	  plane a = query(1, 1, N, i, j, 0);
	  // print(1, 1, N);
	  cout << a.x[3] << " " << a.x[2] << " " << a.x[0] << " " << a.x[1] << endl;
        }
      else if(C == 'X')
        {
	  // print(1, 1, N);
	  mirror(1, 1, N, i, j, 0, 2);
	  //print(1, 1, N);
        }
      else
        {
	  mirror(1, 1, N, i, j, 0, 1);
	  //print(1, 1, N);
        }
    }
  return 0;
}
