#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
  vector<int> prevSmaller(vector<int> &arr)
  {
    //  code here
    int n = arr.size();
    stack<int> st;
    vector<int> Pse(n, 0);
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && st.top() >= arr[i])
      {
        st.pop();
      }
      Pse[i] = st.size() == 0 ? -1 : st.top();
      st.push(arr[i]);
    }
    return Pse;
  }
};