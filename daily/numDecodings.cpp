//
// Created by shimeng on 2021/4/21.
//

#include "common.h"

using namespace std;

/**
 * 回溯法，超时。时间复杂度是O(2^n)：对于任意一个位置pos,都有2种可能，即使提前剪枝，
 * 在最坏情况下也是O(2^n)时间复杂度。
 * @param str
 * @param pos
 * @return
 */
int dfs(string &str, int pos) {
    if (pos >= str.size()) {
        return 1;
    }
    if (str[pos] == '0') {
        return 0;
    }

    int res = dfs(str, pos+1);
    if (pos + 1 < str.size() && str[pos] == '1' || (str[pos] == '2' && '0' <= str[pos+1] && str[pos+1] <= '6') ) {
        res += dfs(str, pos+2);
    }
    return res;
}

/**
 * 记忆化搜索，每当搜索到当前位置对应剩余位置的可能组合，就记录下来，避免大量重复计算。
 * @param str
 * @param pos
 * @param record
 * @return
 */
int dfsWithRecord(string &str, int pos, vector<int> &record) {
    if (pos >= str.size()) {
        return 1;
    }
    if (str[pos] == '0') {
        return 0;
    }
    if (record[pos] != -1) {
        return record[pos];
    }
    int res = dfsWithRecord(str, pos+1, record);
    if (pos + 1 < str.size() && (str[pos] == '1' || (str[pos] == '2' && '0' <= str[pos+1] && str[pos+1] <= '6')) ) {
        res += dfsWithRecord(str, pos+2, record);
    }
    record[pos] = res;
    return res;
}



int numDecodings(string s) {
    int res = 0;
    // method 1
//    res = dfs(s, 0);

// method 2
//    vector<int> record(s.size(), -1);
//    res = dfsWithRecord(s, 0, record);

// method 3


    return res;
}

int main()
{
    assert(numDecodings("12") == 2);
    assert(numDecodings("226") == 3);
    assert(numDecodings("02") == 0);
    // 45个1
    assert(numDecodings("111111111111111111111111111111111111111111111") == 1836311903);

    return 0;
}