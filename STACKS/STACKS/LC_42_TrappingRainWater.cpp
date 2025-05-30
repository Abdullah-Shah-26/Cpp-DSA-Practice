class Solution { //? approach 1 - prefix array approach
    public: //! TC = O(n) // SC = O(n)
        int trap(vector<int>& height) {
            int n = height.size();
            vector<int> lmax(n,0); // to store max left boundary for each bar 
            vector<int> rmax(n,0); // to store max right boundary for each bar 
    
            lmax[0] = height[0];
            rmax[n-1] = height[n-1];
    
            // to find left max
            for(int i = 1; i<n; i++){
                lmax[i] = max(lmax[i-1], height[i]);
            }
            // to find right max 
            for(int i = n-2; i>=0; i--){ //reverse loop 
                rmax[i] = max(rmax[i+1], height[i]);
            }
            // to calculate ans
            int ans = 0;
            for(int i = 0; i<n; i++){
                ans += min(lmax[i], rmax[i])- height[i]; // min will decide the amt of water trapped since if we consider max the water will overflow
            }
            return ans;
        }
    };