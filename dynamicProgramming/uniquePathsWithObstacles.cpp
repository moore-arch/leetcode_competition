//
// Created by Apple on 2021/6/9.
//
#include <vector>

using namespace std;
/**
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 *
 * 分析：dp[i][j]表示从起点到[i, j]的路径数量，对于第一行和第一列，只要前面有一个障碍，则从当前点到这一行（列）后续到所有点都不可到达，
 * 对于其他点，则有障碍物的点不可到达，即dp[i][j] = 0
 *
 * 返回从起点到终点不同路径到数量
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/
 *
 * @param obstacleGrid
 * @return
 */
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    using LL = long long;
    const size_t ROW = obstacleGrid.size();
    const size_t COL = obstacleGrid[0].size();
    vector<vector<LL>> dp(ROW, vector<LL>(COL, 0));
    for (int i = 0; i < ROW && !obstacleGrid[i][0]; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < COL && !obstacleGrid[0][j]; ++j) {
        dp[0][j] = 1;
    }

    for (int i = 1; i < ROW; ++i) {
        for (int j = 1; j < COL; ++j) {
            if (obstacleGrid[i][j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return static_cast<int>(dp[ROW - 1][COL - 1]);
}

int main() {

    return 0;
}

