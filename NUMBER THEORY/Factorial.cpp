#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7; 

/* 
Why 1e9 + 7 
- Its very close to INT_MAX
- Cause it makes it easier to store values in INT - type without needing LONG LONG
- Its a Prime No - so Multiplicative Inverse from 1 to 1e9+7 is possible for each values.
*/

int main()
{
  ll fact = 1;
  ll n = 21;
  for(int i = 2; i <= n; i++)
  fact = (i*fact)%mod;
  
  cout << fact << endl; 
}
