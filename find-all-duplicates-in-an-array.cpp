class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> helper(100000, 0); //1 <= val <= 100000

        int index = 0;

        for (int i = 0; i < nums.size(); i ++) {
            if (helper[nums[i]] == 1) {
                nums[index++] = nums[i]; // nums[i] is repeat value
            }
            
            helper[nums[i]] += 1;
        }
        
        return {nums.begin(), nums.begin() + index};
    }

  vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            auto index = abs(nums[i]) - 1;
            if (nums[index] < 0) res.emplace_back(index + 1);
            nums[index] = -nums[index];
        }
        
        return res;
    }
};
