/*
D. Distinct Characters Queries
time limit per test
2 seconds
memory limit per test
256 megabytes

You are given a string s consisting of lowercase Latin letters and q queries for this string.

Recall that the substring s[l;r] of the string s is the string slsl+1…sr. For example, the substrings of "codeforces" are "code", "force", "f", "for", but not "coder" and "top".

There are two types of queries:

    1 pos c (1≤pos≤|s|, c is lowercase Latin letter): replace spos with c (set spos:=c);
    2 l r (1≤l≤r≤|s|): calculate the number of distinct characters in the substring s[l;r].

Input

The first line of the input contains one string s consisting of no more than 105 lowercase Latin letters.

The second line of the input contains one integer q (1≤q≤105) — the number of queries.

The next q lines contain queries, one per line. Each query is given in the format described in the problem statement. It is guaranteed that there is at least one query of the second type.
Output

For each query of the second type print the answer for it — the number of distinct characters in the required substring in this query.
Examples
Input
Copy

abacaba
5
2 1 4
1 4 b
1 5 b
2 4 6
2 1 7

Output
Copy

3
1
2

Input
Copy

dfcbbcfeeedbaea
15
1 6 e
1 4 b
2 6 14
1 7 b
1 12 c
2 6 8
2 1 6
1 7 c
1 2 f
1 10 a
2 7 9
1 10 a
1 14 b
1 1 f
2 1 11

Output
Copy

5
2
5
2
6

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

struct Node
{
  array<int, 26> freq;
  Node() { freq.fill(0); }
};

vector<Node> tree;
string s;

Node merge(const Node &L, const Node &R)
{
  Node res;
  for (int i = 0; i < 26; i++)
  {
    res.freq[i] = L.freq[i] + R.freq[i];
  }
  return res;
}

void build(int i, int l, int r)
{

  if (l == r)
  {
    tree[i].freq[s[l] - 'a'] = 1;
    return;
  }

  int mid = (l + r) >> 1;
  build(2 * i + 1, l, mid);
  build(2 * i + 2, mid + 1, r);

  tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
}

void update(int i, int l, int r, int idx, char ch)
{
  if (l == r)
  {
    tree[i].freq.fill(0);
    tree[i].freq[ch - 'a'] = 1;
    return;
  }

  int mid = (l + r) >> 1;
  if (idx <= mid)
    update(2 * i + 1, l, mid, idx, ch);
  else
    update(2 * i + 2, mid + 1, r, idx, ch);

  tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
}

Node query(int i, int l, int r, int ql, int qr)
{
  if (qr < l || r < ql)
    return Node();

  if (ql <= l && r <= qr)
    return tree[i];

  int mid = (l + r) >> 1;
  Node L = query(2 * i + 1, l, mid, ql, qr);
  Node R = query(2 * i + 2, mid + 1, r, ql, qr);

  return merge(L, R);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  int n = s.size();
  tree.resize(4 * n + 5);

  build(0, 0, n - 1);

  int q;
  cin >> q;
  while (q--)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int idx;
      char ch;
      cin >> idx >> ch;

      idx--;
      s[idx] = ch;
      update(0, 0, n - 1, idx, ch);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      l--, r--;
      Node res = query(0, 0, n - 1, l, r);

      int distinct = 0;
      for (int x : res.freq)
        if (x > 0)
          distinct++;

      cout << distinct << '\n';
    }
  }
  return 0;
}