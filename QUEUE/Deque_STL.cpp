#include<deque>  //similar to list 
#include<iostream>
using namespace std;
        int main(){
            deque<int>d;

            d.push_back(10);
            d.push_front(20);
            
            cout<< d.front()<<endl;

            d.pop_front();
            
            cout<< d.front() <<endl;
        }