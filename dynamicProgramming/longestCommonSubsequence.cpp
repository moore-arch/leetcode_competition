/*
 * @Author: your name
 * @Date: 2021-05-27 19:33:57
 * @LastEditTime: 2021-05-27 20:46:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcode_competition/dynamicProgramming/longestCommonSubsequence.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * @description: 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
 * 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）
 * 后组成的新字符串。
 * @param {string} text1
 * @param {string} text2
 * @return {*}
 */
int longestCommonSubsequence(string text1, string text2) {
    const size_t M = text1.length();
    const size_t N = text2.length();
    vector<vector<int>> dp(M+1, vector<int> (N+1, 0));

    /**
     * dp[i][j] 表示text1[0, i-1]和text2[0, j-1]的最长公共字串
     * 
     * dp[i][j] = dp[i-1][j-1] + 1  when text1[i-1] == text2[j-1]
     *            max(dp[i-1, j], dp[i][j-1]) when text1[i-1] != text2[j-1]
     */
    for (unsigned i = 1; i <= M; ++i) {
        char ch = text1[i-1];
        for (int j = 1; j <= N; ++j) {
            if (ch == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[M][N];
}


inline void show(string a, string b, int ans) {
    cout << longestCommonSubsequence(a, b) << " except: " << ans << endl;
}


int main()
{
    show("abcde", "ace", 3);
    show("abc", "abc", 3);
    show("abc", "def", 0);

    return 0;
}