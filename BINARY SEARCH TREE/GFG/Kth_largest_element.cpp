class Solution {
    public:
    // we will reverse inorder trqversal _ LNR _ RNL to visit nodes
    // in descending order
    void Klargest(Node* root, int &k, int &ans)
    {
        if(!root)
        return;
        
        // pehle right jao 
        Klargest(root->right, k, ans);
        k--;// k decrease kardiya kyu ki mein uss node ko access karne wala hoon
        
        if(k == 0) // ans mil chuka hay 
        ans = root->data;
        
        if(k <= 0) // then left check karne ki zarurat nai hay
        return;
        
        //else left jao agao k 0 nai hua to
        Klargest(root->left, k, ans);
        
    }
    
      int kthLargest(Node *root, int k) {
          int ans;
          Klargest(root, k, ans);
          return ans;
      }
  };