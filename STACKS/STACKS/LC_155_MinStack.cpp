class MinStack {
    public:
            //! Approach - 1 // stack with pair of value and minValue(curr min val of stack)
               
            stack<pair<in t, int>>s;
    
        MinStack() { 
        }
        
        void push(int val) {
            if(s.empty()){ // if stack is empty value and min value is same
                s.push({val , val});
            }
            else{
                int minVal = min(val,s.top().second); 
                s.push({val,minVal}); // push these values again at top
            }
        }
        
        void pop() {
            s.pop();
        }
        
        int top() {
            return s.top().first;
        }
        
        int getMin() {// returns min val = stack ke top par ki 2nd val
            return s.top().second;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */