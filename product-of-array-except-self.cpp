class Solution {
public:
    vector<int> productExceptSelf(vector<int>& input) {
        vector<int> res(input.size(), 0);

        int p_all = 1;
        int zero_cnt = 0;

        for (int i = 0; i < input.size(); i++) {

            if (zero_cnt > 1) return res;

            if (!input[i]) {
                zero_cnt++;
            } else {
                p_all *= input[i];
            }
        }

        if (zero_cnt > 1) return res;

        for (int i =0; i < input.size(); i++) {
            if (!zero_cnt) {
                
                res[i] = p_all / input[i];
                
            } else if (!input[i]) {
                
                res[i] = p_all;
            
            }
        }
        
        return res;
    }
};
