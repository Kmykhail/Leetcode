iclass Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m, vector<int>(n));

        // each elem of last row and col = 1
        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                if (row == m - 1 || col == n - 1) {
                    res[row][col] = 1;
                } else {
                    continue;
                }
            }
        }
        
        // for pos (row, col) = (row + 1, col) + (row, col + 1) 
        for (int row = m - 2; row >= 0; row--) {
            for (int col = n - 2; col >= 0; col--) {
                res[row][col] = res[row + 1][col] + res[row][col + 1];
            }
        }
        
        return res[0][0];
    }
};
