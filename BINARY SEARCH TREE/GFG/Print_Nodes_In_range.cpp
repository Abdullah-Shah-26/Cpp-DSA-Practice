int n1,n2; // global values banado
class Solution {
  public:
    void find(Node* root , vector<int>& ans){
        if(!root)
        return;
        
        // root range mein hay kya check karo
        if(root->data > n1 && root->data > n2) // root ka data range se bada hay go to left
        find(root->left , ans);
        
        else if(root->data < n1 && root->data < n2) // root ka data range se chota hay go to right
        find(root->right, ans);
        
        else{ // root range mein hay then uske left and right subtree mein dekho and L N R (sorted )order mein ans mein dalo 
            
            find(root->left , ans); // l
            ans.push_back(root->data); // N
            find(root->right, ans); // R 
            
        }
        
    }
};