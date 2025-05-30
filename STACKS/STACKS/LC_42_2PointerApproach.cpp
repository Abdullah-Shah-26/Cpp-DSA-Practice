class Solution {
    public: // TC = O(N) // SC = O(1)
        int trap(vector<int>& height){
            int n = height.size();
            int ans = 0;
            int l = 0;
            int r = n-1;
            int lmax = 0; // represent left and right max at any pt of time 
            int rmax = 0; 

            while(l < r){
                // to evaluate boundaries
                lmax = max(lmax, height[l]); 
                rmax = max(rmax, height[r]);
            
                if(lmax < rmax){//then left boundary will be deciding factor of water trapped since it is small
                    ans += lmax - height[l];
                    l++;
                }
                else{ //then right boundary will be deciding factor 
                    ans += rmax - height[r];
                    r--;
                }
            
            }
            return ans;
        } 

};