#include <stdio.h>

int main()
{
  int N, s, i;
  long long m1 = 1, m2 = 1;
  int zero1 = 0, zeroall = 0;
  int zeroi;
  scanf("%d", &N);
  s = N / 2;
  int l[N];
  
  for(i = 0; i < s && !zeroall; i++)
    {
      scanf("%d", l+i);
      if(l[i]) 
	m1 *= l[i];
      else if(!zero1) {zeroi = i; zero1 = 1;}
      else zeroall = 1;
    }

  for(i = s; i < N && !zeroall; i++)
    {
      scanf("%d", l+i);
      if(l[i]) 
	m2 *= l[i];
      else if(!zero1) {zeroi = i; zero1 = 1;}
      else zeroall = 1;
    }
  
  if(zeroall)
    {
      for(; i < N; i++)
	scanf("%d", l+i);
      
      for(i = 0; i < N; i++)
	printf("0\n");
    }
  else if(zero1)
    {
      for(i = 0; i < s; i++)
	if(zeroi == i) printf("%lld\n", m1 * m2);
	else printf("0\n");
      
      for(i = s; i < N; i++)
	if(zeroi == i) printf("lld\n", m1 * m2);
	else printf("0\n");
    }
  else
    {
      for(i = 0; i < s; i++)
	printf("%lld\n", (m1 / l[i]) * m2);
      
      for(i = s; i < N; i++)
	printf("%lld\n", (m2 / l[i]) * m1);
    }
  return 0;
}
