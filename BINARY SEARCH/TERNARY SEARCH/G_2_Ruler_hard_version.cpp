#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a) \
  for (auto& x : (a)) cin >> x
#define pv(a)                                   \
  do {                                          \
    for (const auto& x : (a)) cout << x << ' '; \
    cout << '\n';                               \
  } while (0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

/*
==========================



==========================
*/

int check(int a, int b) {
  if (a > b) swap(a, b);

  cout << "? " << a << " " << b << endl;

  int area;
  cin >> area;

  if (area == a * b)
    return 0;
  else if (area == a * (b + 1))
    return 1;
  else
    return 2;
}

void solve() {
  int l = 1, r = 1000, best = r;

  while (l <= r) {
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;
    int res = check(mid1, mid2);
    
    if(res == 0){
      l = mid2 + 1;
    }
    else if(res == 1){
      best = min(best, mid2);
      l = mid1 + 1;
      r = mid2 - 1;
    }
    else{
      best = min(best, mid1);
      r = mid1 - 1;
    }
  }

  cout << "! " << best << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}