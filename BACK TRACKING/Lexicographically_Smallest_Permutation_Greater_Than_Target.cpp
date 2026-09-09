#include <bits/stdc++.h>
using namespace std;

// TC = O(N * 26)

class Solution {
public:
  string ans = "";

  bool solve(string &cur, vector<int> &cnt, string &target, int i,  bool greater) {
    if (i == target.size()) {
      if (greater) {
        ans = cur;
        return true;
      }
      return false;
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (cnt[ch - 'a'] == 0)
        continue;

      if (greater == false && ch < target[i])
        continue;

      // Do
      cur.push_back(ch);
      cnt[ch - 'a']--;

      bool isGreater = greater || (ch > target[i]);

      // Explore
      if (solve(cur, cnt, target, i + 1, isGreater))
        return true;

      // Undo
      cnt[ch - 'a']++;
      cur.pop_back();
    }

    return false;
  }

  string lexGreaterPermutation(string s, string target) {
    vector<int> cnt(26, 0);

    for (char ch : s)
      cnt[ch - 'a']++;

    string cur;

    solve(cur, cnt, target, 0, false);

    return ans;
  }
};