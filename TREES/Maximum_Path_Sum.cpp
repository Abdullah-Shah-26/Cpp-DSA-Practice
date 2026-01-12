
//  Definition for a binary tree node.
 struct TreeNode
 {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

#include <bits/stdc++.h>
 using namespace std;
 using ll = long long;
#define fastio                 \
   ios::sync_with_stdio(false); \
   cin.tie(nullptr);

 class Solution
 {
 public:
   int solve(TreeNode *root, int &maxi)
   {
     if (!root)
       return 0;

     int ls = solve(root->left, maxi);
     int rs = solve(root->right, maxi);

     // Edge cases -- >> -ve path sum from anywhere will only decrease overall sum
     if (ls < 0)
       ls = 0;
     if (rs < 0)
       rs = 0;

     maxi = max(maxi, ls + rs + root->val);

     return root->val + max(ls, rs);
   }

   int maxPathSum(TreeNode *root)
   {
     int maxi = INT_MIN;
     solve(root, maxi);
     return maxi;
   }
 };