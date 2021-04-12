//
// Created by shimeng on 2021/4/11.
//

#include "headers/common.h"

using namespace std;

/**
 * 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
 * 丑数 就是只包含质因数 2、3 和/或 5 的正整数。
 * @param n 第n个丑数
 * @return
 */
int nthUglyNumber(int n) {
    if (n <= 0) {
        return 0;
    }
    vector<int> record(n);
    record[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0;
    for (int i = 1; i < n; ++i) {
        int num2 = 2*record[p2];
        int num3 = 3*record[p3];
        int num5 = 5*record[p5];
        int min_value = min(min(num2, num3), num5);
        if (num2 == min_value) {
            ++p2;
        }
        if (num3 == min_value) {
            ++p3;
        }
        if (num5 == min_value) {
            ++p5;
        }
        record[i] = min_value;
    }
    return record[n-1];
}

int main() {

    assert(nthUglyNumber(1) == 1);
    assert(nthUglyNumber(2) == 2);
    assert(nthUglyNumber(3) == 3);
    assert(nthUglyNumber(10) == 12);
    assert(nthUglyNumber(1690) == 2123366400);

    return 0;
}
