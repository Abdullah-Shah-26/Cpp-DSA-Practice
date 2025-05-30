//!  L N R - printing order 
void InOrder(Node* root)
{
    //base case
    if(root == NULL)
    return;
    
    //left
    InOrder(root->left);
    //Node
    cout<<root->data<<" ";
    //right
    InOrder(root->right);

}