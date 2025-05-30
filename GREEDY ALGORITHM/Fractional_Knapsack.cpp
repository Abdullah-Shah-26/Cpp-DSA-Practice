class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        
        if(n == 0 || capacity == 0)
        return 0.0;
        
        // build an array of ratio - val/wt
        vector<pair<double<pair<int, int>>>items;
        items.reserve(n);
        
        
        for(int i = 0; i < n ; i++)
        {
            items.push_back({double(val[i]/wt[i]), {wt[i], val[i]}});
        }
        
        // sort in descending order based on val/wt
        sort(items.begin(), items.end(),[](auto &a , auto &b){
            return a.first > b.first
        });
        
        double totalvalue = 0.0;
        
        
        for(auto &item : items)
        {
            if(capacity == 0)
            break;
            
            int weight = item.second.first;
            int value = item.second.second;
            double ratio = item.first; // weight / value
            
            if(weight <= capacity)
            {
                // take whole item
                totalvalue += value;
                capacity -= weight;
                
            }
            else{
                // take a fraction 
                //weight > capacity
                totalvalue += ratio * capacity;
                capacity = 0;
            }
        }
        
        return std::round(totalvalue * 1e6)/1e6;
        
;    }
}