/*
D. The Child and Sequence
time limit per test
4 seconds
memory limit per test
256 megabytes

At the children's day, the child came to Picks's house, and messed his house up. Picks was angry at him. A lot of important things were lost, in particular the favorite sequence of Picks.

Fortunately, Picks remembers how to repair the sequence. Initially he should create an integer array a[1], a[2], ..., a[n]. Then he should perform a sequence of m operations. An operation can be one of the following:

    Print operation l, r. Picks should write down the value of .
    Modulo operation l, r, x. Picks should perform assignment a[i] = a[i] mod x for each i (l ≤ i ≤ r).
    Set operation k, x. Picks should set the value of a[k] to x (in other words perform an assignment a[k] = x).

Can you help Picks to perform the whole sequence of operations?
Input

The first line of input contains two integer: n, m (1 ≤ n, m ≤ 105). The second line contains n integers, separated by space: a[1], a[2], ..., a[n] (1 ≤ a[i] ≤ 109) — initial value of array elements.

Each of the next m lines begins with a number type .

    If type = 1, there will be two integers more in the line: l, r (1 ≤ l ≤ r ≤ n), which correspond the operation 1.
    If type = 2, there will be three integers more in the line: l, r, x (1 ≤ l ≤ r ≤ n; 1 ≤ x ≤ 109), which correspond the operation 2.
    If type = 3, there will be two integers more in the line: k, x (1 ≤ k ≤ n; 1 ≤ x ≤ 109), which correspond the operation 3.

Output

For each operation 1, please print a line containing the answer. Notice that the answer may exceed the 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int, int>;
using ppi = pair<pair<int, int>, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

static const auto fastio = []()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

vll arr, tree, maxTree;

void build(int i, int l, int r)
{
  if (l == r)
  {
    tree[i] = arr[l];
    maxTree[i] = arr[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(2 * i + 1, l, mid);
  build(2 * i + 2, mid + 1, r);

  tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  maxTree[i] = max(maxTree[2 * i + 1], maxTree[2 * i + 2]);
}

void updatePoint(int i, int l, int r, int idx, ll x)
{
  if (l == r)
  {
    tree[i] = x;
    maxTree[i] = x;
    return;
  }
  int mid = (l + r) >> 1;
  if (idx <= mid)
    updatePoint(2 * i + 1, l, mid, idx, x);
  else
    updatePoint(2 * i + 2, mid + 1, r, idx, x);

  tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  maxTree[i] = max(maxTree[2 * i + 1], maxTree[2 * i + 2]);
}

void updateMod(int i, int l, int r, int ql, int qr, ll x)
{
  if (l > qr || r < ql || maxTree[i] < x)
    return;

  if (l == r)
  {
    tree[i] %= x;
    maxTree[i] = tree[i];
    return;
  }

  int mid = (l + r) >> 1;

  updateMod(2 * i + 1, l, mid, ql, qr, x);
  updateMod(2 * i + 2, mid + 1, r, ql, qr, x);

  tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  maxTree[i] = max(maxTree[2 * i + 1], maxTree[2 * i + 2]);
}

ll querySum(int i, int l, int r, int ql, int qr)
{
  if (l > qr || r < ql)
    return 0;

  if (l >= ql && r <= qr)
    return tree[i];

  int mid = (l + r) >> 1;

  return querySum(2 * i + 1, l, mid, ql, qr) + querySum(2 * i + 2, mid + 1, r, ql, qr);
}

int main()
{
  int n, m;
  cin >> n >> m;

  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  tree.resize(4 * n);
  maxTree.resize(4 * n);
  build(0, 0, n - 1);

  while (m--)
  {
    int type;
    cin >> type;

    if (type == 1)
    {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << querySum(0, 0, n - 1, l, r) << endl;
    }
    else if (type == 2)
    {
      int l, r;
      ll x;
      cin >> l >> r >> x;
      l--, r--;

      updateMod(0, 0, n - 1, l, r, x);
    }
    else
    {
      int k;
      ll x;
      cin >> k >> x;
      updatePoint(0, 0, n - 1, k - 1, x);
    }
  }
}