#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

struct DSU{
  vector<int>parent;
  // TC = O(N Log N)
  // SC = O(N + maxEnd)
  DSU(int n){
    parent.resize(n + 2);
    for(int i = 0; i <= n+1; i++){
      parent[i] = i;
    }
  }

 // Finds next free day >= st
  int find(int x){
    if(parent[x] == x){
      return x;
    }
    return parent[x] = find(parent[x]);  
  }

  // Attended event of this day - Mark as used
  void use(int d){
    parent[d] = find(d + 1);
  }
};

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
    int n = events.size();
    // Sort by end
    sort(begin(events),end(events),[](auto &a, auto &b){
      return a[1] < b[1];
    });
    int maxEnd = events.back()[1];
    DSU dsu(maxEnd);
    int cnt = 0;
    for(auto &event : events){
      int s = event[0];
      int e = event[1];
      int d = dsu.find(s);

      if(d <= e){
        cnt++;
        dsu.use(d);
      } 
    }
    return cnt;
    }
};