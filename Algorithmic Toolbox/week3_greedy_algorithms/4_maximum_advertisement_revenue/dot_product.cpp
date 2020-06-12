#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#define lli long long int
using namespace std;

/*
OPTIMAL GREEDY SOLUTION BY USING DEQUE
*/

lli max_dot_product(vector<int> a, vector<int> b) 
{
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  deque<int> c;
  for(int i=0;i<a.size();i++)
    c.push_back(a[i]);
  deque<int> d;
  for(int i=0;i<b.size();i++)
    d.push_back(b[i]);


  lli p,q,r,s,maxx,summ=0;

  while(!c.empty() && !d.empty())
  {
	    if (c.front()==0)
	    {
	      c.pop_front();
	      continue;
	    }

	    if (c.back()==0)
	    {
	    	c.pop_back();
	    	continue;
	    }

	    if (d.front()==0)
	    {
	    	d.pop_front();
	    	continue;
	    }

	    if (d.back()==0)
	    {
	    	d.pop_back();
	    	continue;
	    }

	    p = (lli)(c.front()*d.front());
	    q = (lli)(c.front()*d.back());
	    r = (lli)(c.back()*d.front());
	    s = (lli)(c.back()*d.back());

	    maxx = max(p,max(q,max(r,s)));
	    summ += maxx;

	    if (maxx==p)
	    {
	    	c.pop_front();
	    	d.pop_front();
	    }
	    else if (maxx==q)
	    {
	    	c.pop_front();
	    	d.pop_back();
	    }
	    else if (maxx==r)
	    {
	    	c.pop_back();
	    	d.pop_front();
	    }
	    else
	    {
	    	c.pop_back();
	    	d.pop_back();
	    }
  }

  return summ;

}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
