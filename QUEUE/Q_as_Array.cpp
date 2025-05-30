#include<iostream>       //! IMPLEMENTATION OF Q USING ARRAY
using namespace std;
// TC = O(1) for all operations
// SC = O(n) - since we are using arr as queue
class queue{
    int size = 4;
    int arr[4]; // or *arr
    int st = -1;
    int end = -1;
    int currsize = 0;

    public:
    queue(){
        // arr = new int[size]
    }


    void push(int x){
        if(currsize == size){ // queue capacity is full
           cout<<"Queue is full \n";
           return; 
        }
        if(currsize == 0){ //giving both st and end pt of queue
            st = 0;
            end = 0;
        }
        else{ // more than 1 element
            end = (end + 1)% size; //only end moves
            // since arr size is fixed end may go to same idx 
        }
        arr[end] = x;
        currsize++;
    }


    void pop(){
        if(currsize == 0){
            cout<<"queue is empty\n";
            return ;
        }
        int element = arr[st]; // storing element to be deleted
        if(currsize == 1){ //destroying queue only 1 element
            st = end = -1;
        }
        else{
            // since arr size is fixed start may go to same idx 
            st = (st+1)% size;
            currsize--;
            return;
        }
    }


    int top(){ //front 
        if(currsize == 0){
            cout<< "no element found\n";
            return -1;
        }
        return arr[st];
    }                         

    int Size(){
        return currsize;
    }

    bool empty (){
        return currsize == 0;
    }

    void display(){
        if(currsize == 0){
            cout<<"no element found";
            return;
        }
        for(int val:arr){
            cout<< val << endl;
        }
    }
};


int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.display();
    cout<<" size of queue is "<< q.Size()<<endl;
    cout<<" is q empty "<< q.empty();

}