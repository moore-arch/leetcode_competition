//
// Created by shimeng on 2021/5/16.
//
#include "common.h"

using namespace std;

/**
 * 暴力枚举 O(n^2), 超时
 * @param nums
 * @return
 */
int findMaximumXOR_(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            res = max(res, nums[i]^nums[j]);
        }
    }
    return res;
}

/**
 * todo, 太难了，后续再看吧
 * https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/
 * @param nums
 * @return
 */
int findMaximumXOR(vector<int> &nums) {
    // 去除符号位
    const int BIT_LIMIT = 31;
    int cur = 0;
    for (int offset = BIT_LIMIT - 1; offset >= 0; --offset) {
        set<int> seen;
        // 将所有的 res^k(a[j]) 放入哈希表中
        for (int item : nums) {
            seen.insert(item >> offset);
        }
        // cur 是 最高位到第offset+1个二进制位为止的部分
        // cur 的第offset+2位 重置为1，记为next
        int next = 2*cur + 1;
        bool found = false;

        // 枚举nums[i]
        for (int item : nums) {
            if (seen.count(next ^ (item >> offset))) {
                found = true;
                break;
            }
        }

        if (found) {
            cur = next;
        }
        else {
            // 没有找到对应的i和j，则第k位只能位0
            cur = next - 1;
        }
    }

    return cur;
}

int main()
{


    return 0;
}
