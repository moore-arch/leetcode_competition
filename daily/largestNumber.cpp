//
// Created by shimeng on 2021/4/12.
//

#include "common.h"
using namespace std;

/**
 * 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
 * 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 *
 * 思路：
 * 对数字排序，排序依据是：如果ab比ba能组成更大的数字，那么a就比b靠前
 * @param nums 输入数组
 * @return 最大数字对应的字符串
 */
string largestNumber(vector<int> nums) {
    vector<string> record(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        record[i] = to_string(nums[i]);
    }
    sort(record.begin(), record.end(), [] (string &a, string &b) -> bool {
        return a+b > b+a;
    });

    string res;
    if (record[0] == "0") {
        res = "0";
    } else {
        for (auto & it : record) {
            res += it;
        }
    }

    return res;
}

int main() {
    assert(largestNumber({10,2}) == "210");
    assert(largestNumber({3,30,34,5,9}) == "9534330");
    assert(largestNumber({1}) == "1");
    assert(largestNumber({10}) == "10");
    assert(largestNumber({0, 0}) == "0");

    return 0;
}

