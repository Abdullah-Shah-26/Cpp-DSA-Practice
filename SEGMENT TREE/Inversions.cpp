/*
A. Inversions
time limit per test
1 second
memory limit per test
1024 megabytes

Given a permutation pi of n elements, find for each i the number of j such that j<i and pj>pi.
Input

The first line contains the number n (1≤n≤105), the second line contains n numbers pi. It is guaranteed that pi form a permutation of numbers from 1 to n.
Output

Print n numbers, the i-th number is equal to the number of j such that j<i and pj>pi.
Example
Input
Copy

5
4 1 3 5 2

Output
Copy

0 1 1 0 3 
*/

#include <bits/stdc++.h>
using namespace std;

class SegTree{
  private:
  int n;
  vector<int>tree;

  void update(int i, int l,int r,int idx)
  {
    if(l == r)
    {
      tree[i] += 1;
      return;
    }
    int mid = (l+r) >> 1;
    if(idx <= mid)
    update(2*i+1, l, mid, idx);
    else
    update(2*i+2, mid+1, r, idx);

    tree[i] = tree[2*i+1] + tree[2*i+2];
  }

  int query(int idx, int l,int r,int ql, int qr)
  {
    if(ql > r || qr < l)
    {
      return 0;
    }
    if(l >= ql && r <= qr)
    return tree[idx];

    int mid = (l + r) >> 1;
    return query(2*idx + 1, l, mid, ql, qr) + query(2*idx+2, mid+1, r, ql, qr);
  }

  public:
  
  SegTree(int size)
  {
    n = size;
    tree.assign(4*n, 0);
  }
  void add(int idx)
  {
    update(0,1,n,idx);
  }
  int rangeSum(int l,int r)
  {
    if(l > r) return 0;
    return query(0, 1, n, l, r);
  }
};

int main()
{
  int n;
  cin>> n;
  vector<int>arr(n);
  for(int i = 0;i < n;i++) cin >> arr[i];

  SegTree st(n);
  vector<int>ans(n);

  for(int i = 0;i <n; i++)
  {
    ans[i] = st.rangeSum(arr[i] + 1,n);
    st.add(arr[i]);
  }
  for(auto &i : ans)
  cout << i << " ";

  return 0;
}