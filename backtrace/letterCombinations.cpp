//
// Created by shimeng on 2021/4/12.
//
#include "common.h"


using namespace std;

vector<string> table {"", "", "abc", "def",
                      "ghi","jkl","mno",
                      "pqrs","tuv","wxyz"};

/**
 * 给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 1()      2(abc)  3(def)
 * 4(ghi)   5(jkl)  6(mno)
 * 7(pqrs)  8(tuv)  9(wxyz)
 * @param digits 数字按键
 * @return 所有可能的字符
 */
void dfs(string &digits, int pos, string str, vector<string> &res) {
    if (pos == digits.length()) {
        res.push_back(str);
        return ;
    }

    for (char ch : table[digits[pos] - '0']) {
        dfs(digits, pos+1, str+ch, res);
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
        return {};
    }
    vector<string> res;
    dfs(digits, 0, "", res);

    return res;
}

int main()
{
    letterCombinations("");
    return 0;
}

