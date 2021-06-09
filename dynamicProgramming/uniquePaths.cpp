//
// Created by Apple on 2021/6/9.
//
#include <vector>

using namespace std;

/**
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 问总共有多少条不同的路径？
 *
 * dp[i][j] 表示从start [0, 0]到[i, j]的路径数量
 * 则有：dp[0][j] = 1, dp[i][0] = 1，即第一行和第一列的所有位置都只有一条路
 * 对于其他位置，则有两类路径：从上方向下或从左方向右。
 * dp[i][j] = dp[i-1][j] + dp[i][j-1]   0 < i, j
 *
 * https://leetcode-cn.com/problems/unique-paths/
 *
 * @param m
 * @param n
 * @return
 */
int uniquePaths(int m, int n) {
    using ULL = unsigned long long;
    vector<vector<ULL>> dp(m, vector<ULL> (n, 1));
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return static_cast<int>(dp[m-1][n-1]);
}


int main()
{

    assert(uniquePaths(3, 7) == 28);
    assert(uniquePaths(3, 2) == 3);

    return 0;
}
