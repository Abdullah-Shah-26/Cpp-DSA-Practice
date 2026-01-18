#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

class Node{
  
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }

};

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* succ = NULL;
        Node* pred = NULL;

        Node* cur = root;

        // successor: smallest > key
        while (cur) {
            if (key >= cur->data) {
                cur = cur->right;
            } else {
                succ = cur;
                cur = cur->left;
            }
        }

        cur = root;

        // predecessor: largest < key
        while (cur) {
            if (key <= cur->data) {
                cur = cur->left;
            } else {
                pred = cur;
                cur = cur->right;
            }
        }

        return {pred, succ}; // your order
    }
};