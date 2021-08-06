class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // move from bottom right to top left
        // for each position grid[row][col] += neighbor with smallest value
        // return value witch will store in pos grid[0][0]

        auto rows = grid.size() - 1;
        auto cols = grid[0].size() - 1;
        
        for (int row = rows; row >= 0; row--) {
            for (int col = cols; col >= 0; col--) {
                if (row == rows || col == cols) {
                    if (col == cols && row > 0) { // for last column
                        grid[row - 1][col] += grid[row][col];
                    }

                    if (row == rows && col > 0) {// for last row
                        grid[row][col - 1] += grid[row][col];
                    }
                    
                } else {
                    grid[row][col] += min(grid[row][col + 1], grid[row + 1][col]);
                }
            }
        }
        
        return grid[0][0];
    } 
};
