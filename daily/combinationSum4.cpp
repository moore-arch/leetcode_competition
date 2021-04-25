#include "common.h"

using namespace std;

int TARGET = 0;
int res = 0;

// method 1, dfs, time out!!!
bool dfs(vector<int> &nums, int value) {
	if (value > TARGET) {
		return false;
	} else if (value == TARGET) {
		res += 1;
		// cout << res << endl;
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (dfs(nums, value + nums[i]) == false) {
			break;
		}
	}
	return true;
}

/**
 * @brief 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。题目数据保证答案符合 32 位整数范围。
 * 
 * @param nums 
 * @param target 
 * @return int 
 */
int combinationSum4(vector<int> nums, int target) {
	sort(nums.begin(), nums.end());
	TARGET = target;
	dfs(nums, 0);
	return res;
}

int main() {
	combinationSum4({1,2,3}, 4);
	cout << res << endl;

	return 0;
}