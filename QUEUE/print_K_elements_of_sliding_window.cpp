#include<bits/stdc++.h>
using namespace std;
void display(queue<int> q){
    while(!q.empty()){
        cout<< q.front() <<" ";
        q.pop();

    }
    cout<<endl;
}

int main(){
    int arr[] = {2,3,1,5,6,7,8};
    int n = 7;
    int k = 3;

    queue<int>q;
    // first k-1 elements ko Q mein push kardo - 2 3 _ 
    for(int i = 0; i<k-1; i++)
    q.push(arr[i]);

    for(int i = k-1; i<n; i++){ // push that idx element (back se)
        q.push(arr[i]);
        display(q); // display the elements
        q.pop();    // pop front element
    }
    return 0;
}