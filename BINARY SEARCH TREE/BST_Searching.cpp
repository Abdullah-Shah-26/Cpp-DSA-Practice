#include<iostream>
using namespace std;
// recursion use karke 
// TC of creating tree = O(n square)   Sc = O(N)
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
//! function to insert values in BST - TC = O(N)
Node* insert(Node* root, int target)
{
    // base case 
    if(!root) // null par pahucnche create node
    {
        Node* temp = new Node(target);
        return temp;
    }

    if(target < root->data) // new node left side dalo
    root->left = insert(root->left, target);

    else // target >= root ->data  -- right side dalo 
    root->right = insert(root->right, target);

    return root;
}
// inorder traversal - sorted aayega 
void inorder(Node *root)
{
    if(!root)
    return;

    // left 
    inorder(root->left);

    // Node
    cout<<root->data<<" ";

    // right
    inorder(root->right);
}
//! Search function - searches element in BST - TC = O(N) = SC 
bool search(Node* root, int target)
{
    if(!root) // null tak pahunch gai yaani target nai mila 
    return 0;

    if(root->data == target)
    return 1;

    if( target < root->data) // search left side
    {
        return search(root->left , target); // ans return karderna 
    }
    else // right side
    return search(root->right, target);
}

int main(){
    int arr[] = {6,3,17,5,11,18,2,1,20,14};
    Node* root = NULL;

    for(int i = 0; i<10; i++)
        root = insert(root, arr[i]);

        cout<<endl;

        cout<<search(root,6);

        // Traverse
        // inorder(root);
}