//
// Created by shimeng on 2021/5/18.
//

#include "common.h"

using namespace std;

/**
 *  形成两个异或相等数组的三元组数目
 *
 *  给你一个整数数组 arr 。
 *  现需要从数组中取三个下标 i、j 和 k ，其中 (0 <= i < j <= k < arr.length) 。
 *  a 和 b 定义如下：
 *  a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
 *  b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
 *  请返回能够令 a == b 成立的三元组 (i, j , k) 的数目。
 *
 *  https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
 *
 * 纯暴力方法，超时！
 * @param arr
 * @return
 */
int _countTriplets(const vector<int>& arr) {
    int res = 0;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i+1; j < arr.size(); ++j) {
            for (int k = j; k < arr.size(); ++k) {
                int a = 0;
                for (int index = i; index < j; ++index) {
                    a ^= arr[index];
                }

                int b = 0;
                for (int index = j; index <= k; ++index) {
                    b ^= arr[index];
                }

                if (a == b) {
                    res += 1;
                }
            }
        }
    }
    return res;
}

/**
 * 优化：三重循环，使用s[i]记录前i个数字异或的结果，则可以在常数时间内计算得出任意区间数字异或的结果
 * 则区间[i,j]内所有数字的异或结果就是：s[i-1]^s[j]
 * 还是比较慢
 *
 * ！！！ 当s[i] == s[k+1]成立时，对[i,k+1]区间内所有的j都是成立的，所以此时可以直接计算j的数量，避免枚举j
 * @param arr
 * @return
 */
int countTriplets(const vector<int>& arr) {
    const size_t LEN = arr.size();
    vector<unsigned> record(LEN+1, 0);
    for (int i = 0; i < LEN; ++i) {
        record[i+1] = record[i]^arr[i];
    }
    int res = 0;

//    for (int i = 0; i < LEN; ++i) {
//        for (int j = i+1; j < LEN; ++j) {
//            for (int k = j; k < LEN; ++k) {
//                if (record[i] == record[k]) {
//                    ++res;
//                }
//            }
//        }
//    }

    for (int i = 0; i < LEN; ++i) {
        for (int k = i+1; k < LEN; ++k) {
            if (record[i] == record[k+1]) {
                res += (k - i);
            }
        }
    }
    return res;
}


int main()
{
    assert(countTriplets({2,3,1,6,7}) == 4);
    assert(countTriplets({1,1,1,1,1}) == 10);
    assert(countTriplets({2,3}) == 0);
    assert(countTriplets({2,3,1,6,7}) == 4);

    return 0;
}
