#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
  vector<int> nextSmallerEle(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> Nse(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && st.top() >= arr[i])
      {
        st.pop();
      }

      Nse[i] = st.size() == 0 ? -1 : st.top();

      st.push(arr[i]);
    }

    return Nse;
  }
};