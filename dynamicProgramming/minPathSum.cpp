//
// Created by Apple on 2021/6/9.
//
#include <vector>

using namespace std;

/**
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 说明：每次只能向下或者向右移动一步。
 *
 * 分析：dp[i][j]代表从[0,0] -> [i, j]的总和
 *
 * dp[i][j] = grid[0][0]    i == j == 0
 *          = dp[i-1][0] + grid[i][0]   j == 0
 *          = dp[0][j-1] + grid[0][j]   i == 0
 *          = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]    0 < i, j
 *
 * @param grid
 * @return
 */
int minPathSum(vector<vector<int>>& grid) {
    const size_t ROW = grid.size();
    const size_t COL = grid[0].size();
    vector<vector<int>> dp(ROW, vector<int> (COL, 0));
    dp[0][0] = grid[0][0];
    for (unsigned i = 1; i < ROW; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (unsigned j = 1; j < COL; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < ROW; ++i) {
        for (int j = 1; j < COL; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return static_cast<int>(dp[ROW - 1][COL - 1]);
}

int main()
{

    return 0;
}
