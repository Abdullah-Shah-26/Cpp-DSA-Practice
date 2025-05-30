class Solution { // method 1 - TC = O(n) SC = O(n)
    //method 2 - TC = O(n) SC = O(1)
public:
void inorder(Node *root, vector<int>& ans){
// inorder traversal
if(!root)
return;

inorder(root->left, ans);      // L 
ans.push_back(root->data); // N
inorder(root->right, ans); // R
}
// Function to check whether a Binary Tree is BST or not.
bool isBST(Node* root) {
vector<int>ans;
inorder(root, ans); // if inorder is in strictly ascending order then its BST 

for(int i = 1; i< ans.size(); i++)
if(ans[i] <= ans[i-1]) // prev should be >= curr
return 0;


return 1;
}
};
//!------------------------------------------------------------------------
class Solution { 
    // method  2 - TC = O(n) SC = O(1)
public:
bool BST(Node* root,int &prev ){

if(!root)
return 1;

// left se jo val ayi wo store karo and check if its true then aage bado 
//   bool l = BST(root->left , prev);
//   if(l == 0)

if(!BST(root->left, prev))
return 0;

if(root->data <= prev)
return 0;

// agar left and node pe check hogayi prop prev <= curr and its true
// update prev before going to right
prev = root->data;
return BST(root->right, prev);
} 

// Function to check whether a Binary Tree is BST or not.
bool isBST(Node* root) {
int prev = INT_MIN;
return BST(root, prev); // func tells if its BST
}


};