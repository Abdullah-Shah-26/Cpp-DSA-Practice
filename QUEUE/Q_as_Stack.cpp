#include<iostream>  //!  IMPLEMENTATION OF Q using STACK - Optimized approach
#include<stack>
using namespace std;
class queue{
    stack<int> s1;
    stack<int> s2;

    public: 

    void push(int x){ // TC = O(1)
        s1.push(x);    
    }
    // integrating both pop and top in one fun since both ops happen at front
    int pop(){  //! TC = O(n)
        if(s1.empty() && s2.empty()){
            cout<< " queue is empty "<<endl;
            return -1;
        }
        if(s2.empty()){ // put all elements of s1 to s2
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        // returning top value
        int topval = s2.top(); // storing val before popping 
        s2.pop();
        return topval;
    }

    bool empty(){
        return s1.empty() == s2.empty();
    }


};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
}