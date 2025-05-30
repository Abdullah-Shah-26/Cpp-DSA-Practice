class Solution { // TC = O(n)
    public:
      // Function to delete a node from BST.
      Node *deleteNode(Node *root, int target) {
        
        
        //  base case - target doesn't exist
        if(!root)
        return NULL;
        
        // target exist 
        // case 1 
        if(root->data > target){ // left side jakar dhoondo
        root -> left = deleteNode(root->left, target);// delete hoke jo address return hoga vo root ke root->left mein store hoga
        return root;
            
        }
        //case 2
        else if(root->data < target){ // right jakar dhoondo
        root -> right = deleteNode(root->right, target);
        return root;
            
        }
        else // case 3 - root->data == target
        {
            // 1 target is leaf node
            if(!root->left && !root->right)
            {
                delete root; 
                return NULL;
            }
            // 2 target ka ek hi child hay -- first store its address , delete , return its child address
                  
                  // only left child exist
              else if(!root->right)
              {
             
                  Node* temp = root->left;
                  delete root;
                  return temp;
              }
                  // only right child exist
              else if(!root->left){
                  Node* temp = root->right;
                  delete root;
                  return temp;
                  
              }
              else // 3.  both child exists
              {
                  // find the greatest element from left subtree
                  
                  Node* child = root->left;
                  Node* parent = root;
                  
                  // right most node tak pahunchna hay - left subrree ke  
                  while(child ->right)
                  {
                      parent = child;  // parent ko kyu rakha -taki relation bana rahe - baar baar child - parent dhoondna na pade
                      child = child ->right;
                  }
                  
                  if(root != parent)
                  {
                      parent->right = child->left;
                      child->left = root->left;
                      child->right = root->right;
                      delete root;
                      return child;
                  }
                  // edge case
                  else{ // parent == root
                      
                      child ->right = root->right;
                      delete root;
                      return child;
                      
                  }
              }
          } 
        
      }
  }