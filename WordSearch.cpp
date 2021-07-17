//
// Created by mykhailenko on 17.07.21.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int row_limit = 0;
    int col_limit = 0;

    bool dfs_recursion(vector<vector<char>>& board, string &word, int indx, int row, int col) {

        if (indx == word.size()) {
            return true;
        }

        if (row < 0 || row >= row_limit ||
            col < 0 || col >= col_limit ||
            word[indx] != board[row][col]) {
            return false;
        }

        auto board_value = board[row][col];
        board[row][col] = '!';

        if (dfs_recursion(board, word, indx + 1, row - 1, col) ||
            dfs_recursion(board, word, indx + 1, row + 1, col) ||
            dfs_recursion(board, word, indx + 1, row, col - 1) ||
            dfs_recursion(board, word, indx + 1, row, col + 1)) {
            return true;
        }

        board[row][col] = board_value;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        row_limit = board.size();
        col_limit = board[0].size();

        for (int row = 0; row <  row_limit; ++row) {
            for (int col = 0; col < col_limit; ++col) {
                if (board[row][col] == word[0]) {
                    if (dfs_recursion(board, word, 0, row, col))
                        return true;
                }
            }
        }

        return false;
    }
};