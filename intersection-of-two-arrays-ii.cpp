class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        auto n1_size = nums1.size();
        auto n2_size = nums2.size();
    
        int k = 0;
        for (int i = 0, j = 0; i < n1_size && j < n2_size; ) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                nums1[k++] = nums1[i++];
                j++;
            }
        }
        
        return {nums1.begin(), nums1.begin() + k};
    }
};
