/*
 * @Author: shimeng
 * @Date: 2021-05-27 19:03:53
 * @LastEditTime: 2021-05-27 19:14:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcode_competition/bitManipulation/hammingDistance.cpp
 */
#include <iostream>

using namespace std;


/**
 * @description: 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
 * 给出两个整数 x 和 y，计算它们之间的汉明距离。
 * @param {int} x
 * @param {int} y
 * @return {hamming distance}
 */
int hammingDistance(int x, int y) {
    int value = x ^ y;
    int res = 0;
    while (value) {
        value = value & (value - 1);
        ++res;
    }
    return res;

    // buildin function
    // return __builtin_popcount(x ^ y);
}

int main() {
    cout << hammingDistance(2, 4) << endl;
    return 0;
}