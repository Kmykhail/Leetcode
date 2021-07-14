//
// Created by mykhailenko on 11.07.21.
//

#include <set>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    using coords_t =  pair<int, int>;

    int row_limit {0};
    int col_limit {0};

    bool inRange(int row, int col) const {
        return (row >= 0 && row < row_limit) && (col >= 0 && col < col_limit);
    }

    void dfs_stack(const vector<vector<char>> &grid, set<coords_t > &marked, const coords_t coord) {
        marked.emplace(coord);

        stack<coords_t > m_stack;
        m_stack.emplace(coord);

        while (!m_stack.empty()) {

            auto top = m_stack.top();
            const auto &[row, col] = top;

            m_stack.pop();

            if (inRange(row - 1, col) && grid[row - 1][col] == '1' && marked.insert({row - 1, col}).second) {
                m_stack.push({row-1, col});
            }

            if (inRange(row + 1, col) && grid[row + 1][col] == '1' && marked.insert({row + 1, col}).second) {
                m_stack.push({row + 1, col});
            }

            if (inRange(row, col -1) && grid[row][col - 1] == '1' && marked.insert({row, col - 1}).second) {
                m_stack.push({row, col - 1});
            }

            if (inRange(row, col + 1) && grid[row][col + 1] == '1' && marked.insert({row, col + 1}).second) {
                m_stack.push({row, col + 1});
            }
        }
    }

    void dfs_recursion(const vector<vector<char>> &grid, set<coords_t > &marked, const coords_t coord) {
        const auto &[row, col] = coord;

        auto val = grid[row][col];
        if (val == '0' || (val == '1' && !marked.emplace(coord).second)) return;

        if (inRange(row - 1, col)) {
            dfs_recursion(grid, marked, {row - 1, col});
        }
        if (inRange(row + 1, col)) {
            dfs_recursion(grid, marked, {row + 1, col});
        }
        if (inRange(row, col -1)) {
            dfs_recursion(grid, marked, {row, col - 1});
        }
        if (inRange(row, col + 1)) {
            dfs_recursion(grid, marked, {row, col + 1});
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int num = 0;

        row_limit = grid.size();
        col_limit = grid[0].size();

        set<coords_t > marked;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                coords_t coord = {row, col};
                if (!marked.count(coord) && grid[row][col] == '1') {

                    /**
                     * Choose one of them
                     * dfs_stack(grid, marked, coord); // stack solution
                     * dfs_recursion(grid, marked, coord); // recursion solution
                     */
                    ++num;
                }
            }
        }

        return num;
    }
};
