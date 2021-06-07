//
// Created by Apple on 2021/6/7.
//

#include "common.h"

using namespace std;

/**
 * 暴力枚举，时间复杂度O(2^n)，不可接受
 * @param nums
 * @param pos
 * @param target
 * @return
 */
int dfs(vector<int> &nums, int pos, int target) {
    if (pos >= nums.size()) {
        return target == 0;
    }
    return dfs(nums, pos + 1, target - nums[pos]) +
           dfs(nums, pos + 1, target + nums[pos]);

}


/**
 * 给你一个整数数组 nums 和一个整数 target 。
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1"
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 *
 * https://leetcode-cn.com/problems/target-sum/
 *
 * 动态规划：
 * 假设nums中元素总和为sum，其中数字前添加负号的数字总和为neg，则剩余数字总和为 sum-neg
 * 因此：(sum - neg) - neg = target
 * 即：neg = (sum - target) / 2
 * 所以，sum - target一定是偶数，切满足上式
 *
 * 此时，问题转化为动态规划：在nums中选取一些数字，这些数字的和是neg。是经典的01背包问题。
 *
 * 定义二维数组dp, dp[i][j]表示前i个元素中选取，和为j的组合个数。则dp[n][neg]即为组合个数。
 * 初始条件：dp[0][0] = 1, dp[0][j] = 0 (j >= 1)，因为数组长度为0切和为0算作一种情况
 * dp[i][j] = dp[i-1][j]                        j < nums[i] (不能选num)
 *          = dp[i-1][j] + dp[i-1][j-nums[i]]   nums[i] <= j (选num和不选num)
 * @param nums
 * @param target
 * @return
 */
int findTargetSumWays(vector<int>& nums, int target) {
    int total = 0;
    for (const auto item : nums) {
        total += item;
    }
    int neg = total - target;
    if (neg & 0x1 || neg < 0) {
        return 0;
    }
    neg /= 2;
    const size_t SIZE = nums.size();
    vector<vector<int>> dp(SIZE + 1, vector<int> (neg + 1 , 0));
    dp[0][0] = 1;
    for (int i = 1; i <= SIZE; ++i) {
        for (int j = 0; j <= neg; ++j) {
            if (j < nums[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
    }

    return dp[SIZE][neg];
}

int main()
{
    vector<int> data {1,1,1,1,1};
    assert(findTargetSumWays(data, 3) == 5);
    return 0;
}

