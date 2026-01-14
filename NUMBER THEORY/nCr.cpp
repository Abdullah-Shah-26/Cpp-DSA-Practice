#include <bits/stdc++.h>
using namespace std;

//* Tell the rth element at that place
int NCR(int n, int r) // TC = O(r)  SC = O(1)
{
  int res = 1;
  for (int i = 0; i < r; i++)
  {
    res = res * (n - i);
    res = res / (i + 1);
  }
  return res;
}

//! Brute Force to Print Nth Row of Pascal's Triangle
//* TC = O(N * R)
void BF(int n)
{
  for(int  c = 1; c < n; c++)
  {
      cout << NCR(n-1,c-1) << " "; 
  }
}

//! Optimized Approach to Print Nth Row of Pascal's Triangle
void Optimized(int n)
{
  int ans = 1;
  cout << ans << " ";
  for (int r = 1; r < n; r++)
  {
    ans = ans * (n - r);
    ans = ans / r;
    cout << ans << " ";
  }
}

//* Print the rth row of Pascal's Triangle
void printPascalRow(int r, int n)
{
  {
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < n; i++)
    {
      ans = ans * (n - i);
      ans = ans / i;
      cout << ans << " ";
    }
  }
}

  int main()
  {
    int n = 5;
    NCR(5, 2);
  }