class MyQueue {
    //! tc of all ops O(1) except pop tc = O(n) amortized tc of pop = O(1) 
    // SC = O(n)
public:

    stack<int> s1; // push operation ke liye 
    stack<int> s2; // pop ke liye

    MyQueue() {
        
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        // CHEKING STACKs KHALI HAY kya 
            if(empty())
            return 0;
            // pop ops from stack 2 - first check whether its empty - if it exists pop element from it
            else if(!s2.empty()){
                int element = s2.top(); // storing the element before popping since we need to return it
                s2.pop();
                return element;
            }
            // s2 empty hay then s1 ke sare elements put s2 mein daldo repeat the above operation since s2 is now not empty
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop(); 
                }
                int element = s2.top(); // storing the element before popping since we need to return it
                s2.pop();
                return element;
            }

    }
    //peek ---  q mein konsa element front par hay?
    int peek() { 
        // if stacks are empty
        if(empty())
        return 0;

        //if s2 ain't empty then s2 ka top is front element of q
        else if(!s2.empty()){
            return s2.top();
        }
    // s2 is empty - put all elements of s1 in s2 and repeat above step
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();

        }

    }
    
    
};