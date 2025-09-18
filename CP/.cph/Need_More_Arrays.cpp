#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
// Greedy boy 
    while(t--)
    {
        int n; 
        cin >> n;

        vector<int>arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        
        }
       int last = -1; 
       int cnt = 0;

       for(int x : arr)
       {
        if( x > last + 1)
        {
            cnt++;
            last = x;
        }
       }
    cout<< cnt << "\n";

    }
    return 0;
}