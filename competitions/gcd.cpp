template <class T>
T gcd(T m, T n)
{
   T r;
   if (m < n) return gcd(n,m);
   r = m%n;
   if (r == 0) return(n);
   else return(gcd(n,r));
}

template <class T>
T gcd(vector<T> num)
{
   T N=num.size();
   if(N==0) cerr<<"Vector given as argument is empty"<<endl;
   sort(num.begin(),num.end());
   T Limit=num[0];
   for(T i=2;i<=Limit;i++)
   {
      T flag=0;
      for(int j=0;j<N;j++)
      {
	 if(num[j]%i==0) flag++;
	 else break;
      }
      if(flag==N) 
      {
	 for(int j=0;j<N;j++)
	    num[j]/=i;
	 return (i*gcd(num));
      }
   }
   return 1;
}
