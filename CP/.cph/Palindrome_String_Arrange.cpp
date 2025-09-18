#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n , k;
        cin >> n >> k;
        string s;
        cin >> s;

        int z = 0;

        for(char ch : s)
        {
            if(ch == '0')
                z++;
        }
        int o = n - z;
        
        int totalpairs = n /2;
        // baddy pairs :)
        int u = totalpairs - k;

        bool ok = true;

        if(u < 0 || u > totalpairs)
        ok = false;

        if( z < u || o < u)
        {
            ok = false;
        }
// even no of left over zeroes
        if((z - u) % 2 != 0 || (o - u) % 2 != 0)
        {
            ok = false;
        }

    cout << (ok ? "YES" : "NO") << "\n";
        
    }
    return 0;
}
    