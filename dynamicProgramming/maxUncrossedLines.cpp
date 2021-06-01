/*
 * @Author: your name
 * @Date: 2021-05-27 21:16:56
 * @LastEditTime: 2021-05-28 11:07:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcode_competition/dynamicProgramming/maxUncrossedLines.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @description: 在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
    * 现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：
    *  nums1[i] == nums2[j]
    * 且绘制的直线不与任何其他连线（非水平线）相交。
    * 请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。
    * 以这种方法绘制线条，并返回可以绘制的最大连线数。
 * 
 * 分析：
 * 每条线都是相同元素构成的，这些元素前后相对位置相同，因此不相交的线两端元素实际上就是LCS，即最长公共子串。
 * 此时，计算最大连接线的数量就转化为计算LCS长度。
 * 使用dp[i][j] 表示nums1[0, i-1], nums2[0, j-1]构成的LCS长度
 * 状态转移方程：
 * dp[i][j] = dp[i-1][j-1] + 1     if nums1[i-1] == nums2[j-1]
 *          = max(dp[i-1][j], dp[i][j-1])   if nums1[i-1] != nums2[j-1]
 * @param {*}
 * @return {*}
 */
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    const size_t M = nums1.size();
    const size_t N = nums2.size();

    vector<vector<int>> dp(M+1, vector<int> (N+1, 0));
    for (unsigned i = 1; i <= M; ++i) {
        const int &number = nums1[i-1];
        for (unsigned j = 1; j <= N; ++j) {
            if (number == nums2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[M][N];
}


int main()
{
    vector<int> a {1, 4, 2};
    vector<int> b {1, 2, 3};
    cout << maxUncrossedLines(a, b) << endl;
    return 0;
}