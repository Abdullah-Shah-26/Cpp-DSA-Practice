#include<iostream> 

//? IMPLEMENTATION OF Q USING LL
//! TC = o(1) for all func except display func - TC = O(n)
// SC = O(N) (where N is the number of elements in the queue).

using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
class queue{
    
    Node* start;
    Node* end;
    int size = 0;

    public:
    queue(){
        start = end = NULL;
    }
    void push(int x){ // creating a new node and pushing it at back of LL
        Node* n = new Node(x);
        if(start == NULL ){
            // No elements in LL st and end will point to new node
            start = end = n;
        }
        else{
            end-> next = n; // updating end to new node
            end = n;
          
        }
        size ++;
        return;
    }

    void pop(){
        if(start == NULL){
            cout<< " queue/LL is empty \n";
            return;
        }
        // delete node dynamically by storing in temp 
        Node* temp = start;
        start = start->next;
        delete temp;
        size--;
    }

    
    int top(){
        if(start == NULL){
            cout<< " queue/LL is empty";
            return -1;
        }
        return start->data;
    }
    bool empty(){
        return start == NULL;
    }

    // to print ll
    void display(){
        Node* temp = start;
        while(temp != NULL){
            cout<< temp->data << endl;
            temp = temp->next;
        }
    }
};
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.display();



    
}