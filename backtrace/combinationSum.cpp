//
// Created by shimeng on 2021/4/21.
//

#include "common.h"

using namespace std;

void dfs(vector<int> &nums, int pos, int target, vector<int> temp, vector<vector<int>> res) {
    if (target == 0) {
        res.push_back(temp);
    }
    const int LEN = nums.size() - 1;
    for (int i = pos; i < LEN; ++i) {
        temp.push_back(nums[i]);
        dfs(nums, pos, target - nums[i], temp, res);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> temp;
    vector<vector<int>> res;
    dfs(candidates, 0, target, temp,res);

    return res;
}


int main()
{
    vector<int> data {2,3,6,7};
    auto res = combinationSum(data, 7);
    for (const auto& line : res) {
        for (int item : line) {
            cout << item;
        }
        cout << endl;
    }
    return 0;
}