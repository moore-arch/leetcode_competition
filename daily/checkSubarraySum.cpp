//
// Created by Apple on 2021/6/2.
//

#include "common.h"

using namespace std;

/**
 * 给你一个整数数组 nums 和一个整数k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：
     * 子数组大小 至少为 2 ，
     * 子数组元素总和为 k 的倍数
 * 如果存在，返回 true ；否则，返回 false 。
 * 如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。
 *
 * 输入：nums = [23,2,4,6,7], k = 6
 * 输出：true
 * 解释：[2,4] 是一个大小为 2 的子数组，并且和为 6 。
 *
 * 输入：nums = [23,2,6,4,7], k = 6
 * 输出：true
 * 解释：[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42。
     * 42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。
     *
 * 分析：首先，最简单的是暴力方法，遍历每一个长度不小于2的子数组并计算长度，判断是否存在，时间复杂度为O(n^3)。
 *  优化：利用前缀和，预先计算从0开始的子数组的和，当每次需要其他子数组的和时，可以直接查表或者一次做差就行，时间复杂度为O(n^2)。
 *  再次优化：判断子数组是不是k的倍数，利用前缀和时，通过做差得出子数组的和，如果此时只储存余数，
 *  则可以将问题转化为子数组起始位置和结束位置余数书否相同。
 *
 * https://leetcode-cn.com/problems/continuous-subarray-sum/
 *
 * @param nums
 * @param k
 * @return
 */
bool checkSubarraySum(const vector<int>& nums, int k) {
    // key is remainder, value is first index of remainder
    unordered_map<int, int> mp;
    // 将余数为0的情况下标记为1，则可以直接简化数组长度判断，
    // 将从头开始的子数组与愿数组中间一部分截取的子数组判断合并
    mp[0] = -1;
    bool exist = false;
    const size_t SIZE = nums.size();
    unordered_map<int, int>::iterator it;
    for (int i = 0, remainder = 0; i < SIZE && !exist; ++i) {
        remainder = (remainder + nums[i]) % k;
        if ((it = mp.find(remainder)) != mp.end()) {
            // 由于已经将余数为0的情况下表记录为-1，此时直接检查子数组长度即可
            // 如果余数为0，则从数组起始位置算起，如果余数不为0，则计算的是数组中间的一部分
            if (i - it->second >= 2) {
                exist = true;
            }
        } else {
            mp[remainder] = i;
        }
    }

    return exist;
}

int main(int argc, char *argv[]) {
    vector<int> data {23,2,6,4,7};
    assert(checkSubarraySum(data, 6) == true);
    assert(checkSubarraySum(data, 13) == false);

    assert(checkSubarraySum({23,2,4,6,6}, 7) == true);

    return 0;
}

