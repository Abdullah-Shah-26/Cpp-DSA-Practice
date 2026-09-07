#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    
    // Mutliset to explore edges in Lexicograpical order
    unordered_map<string, multiset<string>>adj; 
    vector<string> ans;

    int n = tickets.size();

    for (auto &e : tickets)
      adj[e[0]].insert(e[1]);

    stack<string> st;
    st.push("JFK"); // Fixed starting point

    while (!st.empty()) {
      string u = st.top();

      if (adj[u].size() == 0) { // Explored all its neighbbours
        st.pop();
        ans.push_back(u);
      } else {
        auto v = adj[u].begin();
        st.push(*v);
        adj[u].erase(v);
      }
    }

    reverse(begin(ans), end(ans));

    return ans;
  }
};