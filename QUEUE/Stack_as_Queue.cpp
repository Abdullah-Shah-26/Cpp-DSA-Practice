#include<iostream> //! making push costly             // STACK USING Q
#include<queue>   // first push val in q2 --- put all the elements of q1 to q2 --- swap q1 and q2
using namespace std;

class Stack{
    int size;
    queue<int> q1;
    queue<int> q2;

    public:

    Stack(){
        size = 0;
    }

    void push(int val){
        q2.push(val);     //? first push val in q2
        size++;
        while(!q1.empty()){
            q2.push(q1.front());    //? put all the elements of q1 to q2
            q1.pop();
        }
        //swapping queues 
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop(){
        q1.pop();
        size--;
    }

    int top(){
        return q1.front();
    }
    int Size(){
        return q1.size();
    }
};
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<< st.top() << endl;
    st.pop();
    cout<< st.top() << endl;
}