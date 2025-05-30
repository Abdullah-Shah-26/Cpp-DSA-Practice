class Solution {
    public:
      void correctBST(Node* root) {
          // we we'll use morris traversal - inorder TC = O(N)  SC = O(1)
          
          Node* curr = NULL;
          Node* first = NULL, *second = NULL;
          Node* last = NULL, *present = NULL;
          
          while(root){
              // left doesn't exist
              if(!root->left)
              {   //right jane se pehle check koi gadbad to nai hay
                  last = present;
                  present = root;
                  // check for gadbad  - initially last is null  we cant compare null and element
                  // so ensure last exist
                  if(last && last->data > present->data){
                      if(!first) // first NULL hay yani 1st gadbad update both 
                      first = last;
                      
                      second = present; // second gadbad hay update only second
                      
          
                  }
                  
                  root = root->right;
              }
              // left exist
              else
              {   curr = root->left;
                  while(curr->right && curr->right != root){
                      curr = curr -> right;
                  }
                  
                  
                  // Left subtree not Traversed
                  if(!curr->right)
                  {
                      curr->right = root;
                      root = root ->left;
                  }
                  else{// Left subtree already traversed
                      
                       curr->right = NULL;
                       last = present;
                       present = root;
                  // check for gadbad  - initially last is null  we cant compare null and element
                  // so ensure last exist
                      if(last && last->data > present->data)
                      {
                      if(!first) // first NULL hay yani 1st gadbad update both 
                      first = last;
                      
                      second = present; // second gadbad hay update only second
                      }
                      
                      
                      root = root->right;
                  }
              }
          }
          // swap first and second
          int temp = first->data;
          first ->data = second ->data;
          second ->data = temp;
      }
  };