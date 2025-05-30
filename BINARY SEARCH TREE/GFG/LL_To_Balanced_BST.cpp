class Solution { // TC = O(N) == SC (vector)  & SC of rec call stack = O(h) / O(logn)
    public:
    // func to create Balanced BSt from vector - jo mid hay vo node banega
      TNode* BuildBST(vector<int>&Tree, int start, int end){
              
              if(start > end)
              return NULL; // no need to create node there
              
              // acc to question mid is calculated it prefers 2nd value 
              int mid = start + (end - start + 1)/2; // its written this way to avoid int overflow
              TNode* root = new TNode(Tree[mid]);
              
              
              root->left = BuildBST(Tree , start, mid - 1);
              root->right = BuildBST(Tree , mid + 1, end );
              
              return root;
              }
    
      TNode *sortedListToBST(LNode *head) {
              //  first convert LL _ vector
              vector<int>Tree;
              
              while(head){
                  Tree.push_back(head->data);
                  head = head->next;
              }
              return BuildBST(Tree, 0, Tree.size()-1);
      }
  };