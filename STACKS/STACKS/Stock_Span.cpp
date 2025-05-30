#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    //stock prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
     //! SC =O(n) -..-stack
    //solution
     // stores spans
    vector<int>ans(price.size(), 0);//!initialized a vector of size equal to price and all values are 0
    stack<int> s;  // to store greater values for today (previous high) to calculate span = i(curr idx) - prevhigh idx


    for(int i =0; i<price.size(); i++){  //! TC = O(n)  (overall)
        //? since nested loop is running limited times
        while(s.size() > 0 && price[s.top()] <= price[i]){//jo bhi values curr val less hay we'll pop them from stack 
            s.pop();
        }
        if(s.empty()){ //stack is empty -> no prev high
            ans[i] = i+1; //(span)
        }
        else{
            ans[i] = i-s.top(); // stack ka top is prevhigh and we are calculating span = i(curr idx) - prevhigh idx
        }
        s.push(i); //before updating i we store prev i 
    }
// print ans value
for(int val: ans){
    cout<< val<< " ";
}
return 0;
}