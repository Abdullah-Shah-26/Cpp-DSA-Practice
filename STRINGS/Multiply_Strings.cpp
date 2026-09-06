#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";

    int n = num1.size();
    int m = num2.size();

    vector<int> ans(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {

        int x = num1[i] - '0';
        int y = num2[j] - '0';

        int prod = x * y;

        int pos1 = i + j;
        int pos2 = i + j + 1;

        ans[pos2] += (prod % 10); // Last digit
        ans[pos1] += (prod / 10); // Second last digit
      }
    }

    // Handling carry
    for (int i = n + m - 1; i > 0; i--) {
      ans[i - 1] += ans[i] / 10;
      ans[i] %= 10;
    }

    string res = "";

    int i = 0;
    while (i < ans.size() && ans[i] == 0)
      i++;

    while (i < ans.size()) {
      res += char(ans[i] + '0');
      i++;
    }

    return res;
  }
};