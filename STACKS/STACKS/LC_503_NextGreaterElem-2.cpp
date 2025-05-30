class Solution {
    public: //TC = O(n) - overall cause of outer loop inner is taking less as its only poping/pushing in stack once
        /// SC = O(n) - stack
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n,-1);
            stack<int >s;
    // instead of creating an additional array we use idx to use same elements and idx = i%n
            for(int i = 2*n-1; i>=0; i--){// backward loop 
                while(s.size() > 0 && nums[s.top()] <= nums[i%n]){ //why i%n to convert and map values > n 
                    s.pop(); // smaller elements from top of stack are removed
                }
                ans[i%n] = s.empty() ? -1 : nums[s.top()]; //if stack is empty ans = -1 else ans is element at top of stack
                s.push(i%n);
            }
            return ans;
        }
    };