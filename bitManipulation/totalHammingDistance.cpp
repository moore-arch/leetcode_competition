/*
 * @Author: your name
 * @Date: 2021-05-28 19:29:49
 * @LastEditTime: 2021-05-28 19:52:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcode_competition/bitManipulation/totalHammingDistance.cpp
 */

#include <vector>

using namespace std;


/**
 * @description: 两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
 * 
 * 分析：
 *  计算汉明距离时考虑的是同一个比特上的值是否相同，不同比特间不会相互影响。
 *  对于任意一个元素value，如果他的某一比特为1，则只需要查找对应比特为0的数字的数量就可以得到这个比特与其他元素产生的汉明距离
 *  更进一步，对于n个数字的某个比特，假设有c个1，则有（n-c）个0，对应的汉明距离总和就是c*（n-c）
 * @param {*}
 * @return {*}
 */
int totalHammingDistance(vector<int>& nums) {
    const int N = nums.size();
    int res = 0;
    for (unsigned offset = 0; offset < 32; ++offset) {
        int numOfOne = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] & (0x1 << offset)) {
                ++numOfOne;
            }
        }
        res += numOfOne * (N - numOfOne);
    }
    return res;
}

int main()
{
    vector<int> data {4, 14, 2};
    assert(totalHammingDistance(data) == 6);
    
    return 0;
}
