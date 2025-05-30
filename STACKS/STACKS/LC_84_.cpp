class Solution { //! 84. Largest Rectangle in Histogram
    //✅ Time Complexity: O(n) 
//✅ Space Complexity: O(n) - extra arrays and stack
    public:
        int largestRectangleArea(vector<int>& heights){
            // ht is const width is changing = right boundary - left - i
            int n = heights.size();
            vector<int> left(n, 0);// left smaller nearest lsn
            vector<int> right(n, 0); // right smaller nearest rsn
            stack< int> s; // 
            //-> same approach like next greater element
    
            // for rsn
            for(int i = n-1; i>= 0; i--){
                while(s.size()> 0 && heights[s.top()] >= heights[i]){ //stack ke top element >= ht array ke element pop it
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
            }
    
            // if the elements are left remove then from stack for performing lsn 
            while(!s.empty()){
                s.pop();
            }
            
            // for lsn
            for(int i =0; i<n ; i++){
                while(s.size()> 0 && heights[s.top()] >= heights[i]){ //stack ke top element >= ht array ke element pop it
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
            }
            // to calculate largest area of rectangle 
            int ans = 0;
            for(int i = 0; i< n; i++){
                int width = right[i] - left[i] -1; 
            int currArea = heights[i] * width;
            ans = max(ans , currArea);
            }
        
        return ans; 
        }
    
    };