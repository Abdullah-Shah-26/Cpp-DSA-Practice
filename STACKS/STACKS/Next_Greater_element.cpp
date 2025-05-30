#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int> arr = {6, 8, 0, 1, 3};
    stack<int> s;   //to store and fing next greater element
    vector<int> ans(arr.size(), 0); 

    // backward traversing array 
    for(int i = arr.size()-1; i>=0; i--){
        while(s.size() > 0 && s.top() <= arr[i]){
        s.pop(); //! removing element form top of stack which is <= current element
    }
    if(s.empty()){ //* stack is empty ans = -1
    ans[i] = -1;
    }

    else{
   ans[i] = s.top(); // top element is next greater
    }
    s.push(arr[i]); // push curr elem in stack

}
//print 
for(int val : ans ){
    cout<< val<<" ";
}

}