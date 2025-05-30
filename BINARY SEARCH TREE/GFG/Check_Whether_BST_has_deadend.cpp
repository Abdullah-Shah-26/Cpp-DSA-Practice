class Solution{
    public:
  
      bool Dead(Node* root, int lower , int upper){
          if(!root) // if its a null - its not a leaf - to dead end kaise hoga 
          return 0;
          
          // leaf node hay
          if(!root->left && !root->right)
          {
              // check if its a dead end 
              // range of elements that u cant insert in l or R = 1-1 = 0
              if(root->data == lower + 1 && root->data == upper - 1)
              return 1;
              else
              return 0;// not a dead end
          }
          // check karo ki left and right side mein dead node hay kya 
          
          return Dead(root->left , lower , root->data) ||
                 Dead(root->right, root->data , upper);
       }
      
        bool isDeadEnd(Node *root)
        {
          //Your code here
          return Dead(root, 0 ,INT_MAX);
          
        }
  }; 