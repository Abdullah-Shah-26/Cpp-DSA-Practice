// Author: Abdullah = me
#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MOD = 1e9 + 7;
const int INF = 1e18;

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        long long n, a, b;
        cin >> n >> a >> b;
        bool blue_center = ((n - b) % 2 == 0);
        bool red_center = ((n - a) % 2 == 0);
        if (blue_center && (a <= b || red_center))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
