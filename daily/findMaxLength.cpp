//
// Created by Apple on 2021/6/3.
//

#include <vector>
#include <map>

using namespace std;
/**
 * ‼️ important！
 *
 * 给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
 *
 * 连续子数组和的衍生：https://leetcode-cn.com/problems/continuous-subarray-sum/
 * 参见：checkSubarraySum.cpp文件，值得多思考！
 *
 * @param nums
 * @return
 */
int findMaxLength(vector<int>& nums) {
    // key is prefixSum, value is index
    const size_t LEN = nums.size();
    map<int, int> record;
    int maxLength = 0;
    map<int, int>::iterator it;
    for (int i = 0, prefixSum = 0; i < LEN; ++i) {
        if (nums[i] == 1) {
            prefixSum += 1;
        } else {
            prefixSum -= 1;
        }

        if ((it = record.find(prefixSum)) == record.end()) {
            record[prefixSum] = i;
        } else {
            maxLength = max(maxLength, i - it->second + 1);
        }
    }

    return maxLength;
}

