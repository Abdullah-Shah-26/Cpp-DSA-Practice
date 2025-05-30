//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// function Template for C++

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
       // Tc = O(n) 
       // Sc = O(n)  - using stack
       
       stack<int> s;
       
       //empty the q and push in stack
       while(!q.empty()){
           s.push(q.front());
           q.pop();
       }
       
       //empty the stack and put elements back in q
       while(!s.empty()){
           q.push(s.top());
           s.pop();
       }
       return q;
    }
};
