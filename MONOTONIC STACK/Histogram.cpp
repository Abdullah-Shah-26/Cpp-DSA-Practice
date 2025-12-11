#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// Single Pass = O(N) TC
class Solution
{
public:
  int getMaxArea(vector<int> &arr)
  {
    stack<int> st;
    int maxi = 0;
    int n = arr.size();
    // we are gonna calculate pse on fly
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && arr[st.top()] > arr[i])
      {
        int el = st.top();
        st.pop();

        int nse = i;
        int pse = st.size() == 0 ? -1 : st.top();
        maxi = max(maxi, arr[el] * (nse - pse - 1));
      }
      st.push(i);
    }
    // For Left Out untouched el that dont have nse - take as n
    while (!st.empty())
    {
      int nse = n;
      int el = st.top();
      st.pop();
      int pse = st.size() == 0 ? -1 : st.top();
      maxi = max(maxi, arr[el] * (nse - pse - 1));
    }
    return maxi;
  }
};