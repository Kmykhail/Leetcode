class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
    
        int left = 0;
        int right = nums.size() - 1;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            
            const auto l_val = abs(nums[left] * nums[left]);
            const auto r_val = abs(nums[right] * nums[right]);
            
            if (l_val < r_val) {
                res[i] = r_val;
                right--;
            } else {
                res[i] = l_val;
                left++;
            }
        }
        
        return res;
    }
};
