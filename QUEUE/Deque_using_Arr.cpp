#include<iostream>
using namespace std;

class Deque{
    int front, rear, size;
    int *arr;

    public:

    Deque(int n){
        size = n;
        arr = new int[n];
        front = rear = -1; // initializing front and rear with -1
    }

    bool IsEmpty(){
        return front == -1;
    }

    bool IsFull(){
        return (rear +1)%size == front;
    }
    //! push front
    void push_front(int x){
        // check if arr is empty
        if(IsEmpty()){
                front = rear = 0; // put both front & rear at 0 th idx
                cout<<"Pushed "<<x<<" in front\n";
                arr[0] = x ;// and element at 0 th idx
                return;
            }

            // check if deque is full
            else if(IsFull()){
                cout << "deque overflow \n";
                return ;
            }

            // neither empty nor full push front 
            else{
                // front ko ek step back
                front = (front-1+size)%size;
                arr[front] = x;
                cout<<"Pushed "<<x<<" in front\n";
                return;
            }
    }

    //! push back
    void push_back(int x){
        // check if arr is empty
        if(IsEmpty()){
                front = rear = 0; // put both front & rear at 0 th idx
                cout<<"Pushed "<<x<<" in front\n";
                arr[0] = x ;// and element at 0 th idx
                return;
            }

            // check if deque is full
            else if(IsFull()){
                cout << "deque overflow \n";
                return ;
            }

            // neither empty nor full push back
            else{
                // rear ko ek step aage
                rear = (rear+1)%size;
                arr[rear] = x;
                cout<<"Pushed "<<x<<" in back\n";
                return;
            }
    }
    //! pop front
    void pop_front(){
        cout<<"popped "<<arr[front]<<" from from front of deque\n";
        // check if arr is empty
        if(IsEmpty()){
            cout<< " deque Underflow\n";
            return;
        }
        else{
            // single element
            if(front == rear){
                front = rear = -1;
            }
            // more than 1 element
            else 
            // front ko aage badao 
            front = (front+1)%size;
        }
    }

    //! pop back
    void pop_back(){
        cout<<"popped "<<arr[rear]<<" from back of deque\n";
        // chech if arr is empty
        if(IsEmpty()){
            cout<< " deque Underflow\n";
            return;
        }
        else{
           
            // single element
            if(front == rear){
                front = rear = -1;
            }
            // more than 1 element
            else 
            // rear ko peeche lejao 
            rear = (rear - 1 +size)%size; 
        }
    }

    //! starting element
    int start(){
        if(IsEmpty())
            return -1;
            else
            return arr[front];
    }

    //! end element
    int end(){
        if(IsEmpty())
        return -1;
        else
        return arr[rear];
    }
};

int main(){

    Deque dq(5);

    dq.push_back(10);
    dq.push_back(9);
    dq.push_front(13);

    dq.pop_back();
    dq.pop_front();
    cout<<dq.start()<<endl;

}