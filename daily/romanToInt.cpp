//
// Created by shimeng on 2021/5/15.
//

#include "common.h"

using namespace std;

unordered_map<char, int> record {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int romanToInt(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i + 1 < s.size() && record[s[i]] < record[s[i + 1]]) {
            res += (record[s[i + 1]] - record[s[i]]);
            ++i;
        } else {
            res += record[s[i]];
        }
    }
    return res;
}

int main() {
    assert(romanToInt("III") == 3);
    assert(romanToInt("IV") == 4);
    assert(romanToInt("IX") == 9);
    assert(romanToInt("LVIII") == 58);
    assert(romanToInt("MCMXCIV") == 1994);

    return 0;
}

