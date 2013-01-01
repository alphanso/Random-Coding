template <class T>
string tos(T x)
{
  stringstream s; 
  s<<x; 
  return s.str();
}

template <class T>
T froms(string s) 
{
  stringstream ss(s); 
  T x; 
  ss>>x; 
  return x;
}
