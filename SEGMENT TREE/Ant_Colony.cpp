/*
F. Ant colony
time limit per test
1 second
memory limit per test
256 megabytes

Mole is hungry again. He found one ant colony, consisting of n ants, ordered in a row. Each ant i (1 ≤ i ≤ n) has a strength si.

In order to make his dinner more interesting, Mole organizes a version of «Hunger Games» for the ants. He chooses two numbers l and r (1 ≤ l ≤ r ≤ n) and each pair of ants with indices between l and r (inclusively) will fight. When two ants i and j fight, ant i gets one battle point only if si divides sj (also, ant j gets one battle point only if sj divides si).

After all fights have been finished, Mole makes the ranking. An ant i, with vi battle points obtained, is going to be freed only if vi = r - l, or in other words only if it took a point in every fight it participated. After that, Mole eats the rest of the ants. Note that there can be many ants freed or even none.

In order to choose the best sequence, Mole gives you t segments [li, ri] and asks for each of them how many ants is he going to eat if those ants fight.
Input

The first line contains one integer n (1 ≤ n ≤ 105), the size of the ant colony.

The second line contains n integers s1, s2, ..., sn (1 ≤ si ≤ 109), the strengths of the ants.

The third line contains one integer t (1 ≤ t ≤ 105), the number of test cases.

Each of the next t lines contains two integers li and ri (1 ≤ li ≤ ri ≤ n), describing one query.
Output

Print to the standard output t lines. The i-th line contains number of ants that Mole eats from the segment [li, ri].
Examples
Input
Copy

5
1 3 2 4 2
4
1 5
2 5
3 5
4 5

Output
Copy

4
4
1
1

Note

In the first test battle points for each ant are v = [4, 0, 2, 0, 2], so ant number 1 is freed. Mole eats the ants 2, 3, 4, 5.

In the second test case battle points are v = [0, 2, 0, 2], so no ant is freed and all of them are eaten by Mole.

In the third test case battle points are v = [2, 0, 2], so ants number 3 and 5 are freed. Mole eats only the ant 4.

In the fourth test case battle points are v = [0, 1], so ant number 5 is freed. Mole eats the ant 4.
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

struct Node
{
  ll gcd, cnt;
};

vector<Node> tree;
vll arr;

ll gcd(ll a, ll b)
{
  while (b != 0)
  {
    a %= b;
    swap(a, b);
  }
  return a;
}

Node merge(const Node &L, const Node &R)
{
  Node res;

  res.gcd = gcd(L.gcd, R.gcd);

  res.cnt = 0;

  if (res.gcd == L.gcd)
    res.cnt += L.cnt;
  if (res.gcd == R.gcd)
    res.cnt += R.cnt;

  return res;
}

void build(int i, int l, int r)
{
  if (l == r)
  {
    tree[i] = {arr[l], 1};
    return;
  }
  int mid = (l + r) >> 1;
  build(2 * i + 1, l, mid);
  build(2 * i + 2, mid + 1, r);

  tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
}

Node query(int i, int l, int r, int ql, int qr)
{
  if (l > qr || r < ql)
    return {0, 0};

  if (l >= ql && r <= qr)
    return tree[i];

  int mid = (l + r) >> 1;

  Node left = query(2 * i + 1, l, mid, ql, qr);
  Node right = query(2 * i + 2, mid + 1, r, ql, qr);

  return merge(left, right);
}

int main()
{
  int n;
  cin >> n;

  arr.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  tree.resize(4 * n);
  build(0, 0, n - 1);

  int t;
  cin >> t;

  while (t--)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;

    Node res = query(0, 0, n - 1, l, r);

    cout << (r - l + 1) - res.cnt << endl;
  }

  return 0;
}