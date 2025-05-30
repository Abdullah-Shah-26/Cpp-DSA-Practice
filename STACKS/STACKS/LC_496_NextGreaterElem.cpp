class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int>m; //num2 ke liye unka next greater find karna and map mein store karna   
            stack<int>s; //to find next greater element
            // backward traversing array 
        for(int i = nums2.size()-1; i>=0; i--){
            while(s.size() > 0 && s.top() <= nums2[i]){
            s.pop(); //! removing element form top of stack which is <= current element
        }
        if(s.empty()){ //* stack is empty ans = -1 store in map
        m[nums2[i]] = -1;
    
        }
        else {
            m[nums2[i]] = s.top(); // / top element is next greater
        }
          
        s.push(nums2[i]); // push curr elem in stack
    
    }
    
    vector<int> ans;
    for(int i =0; i<nums1.size(); i++){
        ans.push_back(m[nums1[i]]);  //accesing num1 ke NG from map
    }
       return ans;
      }
    };