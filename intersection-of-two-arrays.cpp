class Solution {
public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> n1{nums1.begin(), nums1.end()};
        set<int> n2{nums2.begin(), nums2.end()};
        
        vector<int> res;
        
        for (auto &n1_it: n1) {
            
            if (n2.count(n1_it)) {
                
                res.emplace_back(n1_it);
            
            }
        }        
        
        return res;
    }
};
