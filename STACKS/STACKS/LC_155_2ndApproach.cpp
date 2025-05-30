class MinStack {
    public: 
    //! TC = O(1)    // optimized SC = O(n) -> Since we are pushing/poping single elements in stack
        stack<long long int>s; // to avoid overflow since we're using formula
        long long int minVal;
        //! minvalue = global min value of stack
        MinStack(){

        }

        void push(int val){
            if(s.empty()){//stack is empty simply push val
                s.push(val);
            minVal = val;
        }
        else{
            if(val < minVal){ // min val gets updated  
                s.push(long long int)(2 * val - minVal); //we ll use formula to change this value and push in stack
                //? since if we directly push it and pop it we cannot access the old global min so we're using this formula
                minVal = val; 
            }
        }

        }
        void pop(){
            if(s.top() < minVal){
                minVal = 2 * minVal - s.top(); // now we can get old global value
            }
            s.pop();
        }
        int top(){
            if(s.top() < minVal ){ //here we'll return the exact value we received from user using push
                return minVal;
            }
            return s.top;
        }
        int getMin(){
            return minVal;
        }
};