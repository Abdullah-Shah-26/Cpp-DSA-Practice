#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            int rem = a[i] % k;
            if (rem != 0)
            {
                a[i] += (k - rem); // smallest addition to make divisible by k
            }
        }
        for (auto i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}