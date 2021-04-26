#include "common.h"    

using namespace std;

/**
 * @brief 传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。
 * 传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
 * 返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。
 * https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
 * 
 * @param weights 
 * @param D 
 * @return int 
 */
 // 递增，线性枚举，效率较差
int _shipWithinDays(vector<int>& weights, int D) {
	int total = 0;
	int maxValue = 0;
	for (const int &item : weights) {
		total += item;
		maxValue = max(maxValue, item);
	}
	int res = max(total / D, maxValue);
	while (true) {
		int day = 0;
		int good = 0;
		int pos = 0;
		while (pos < weights.size()) {
			if (good + weights[pos] <= res) {
				good += weights[pos];
				++pos;
			} else {
				good = 0;
				day += 1;
			}
		}
		if (good) {
			day += 1;
		}
		if (day <= D) {
			break;
		}
		res += 1;
	}
	return res;
}

// binary search, fast!
int shipWithinDays(vector<int>& weights, int D) {
	int left = *max_element(weights.begin(), weights.end());
	int right = accumulate(weights.begin(), weights.end(), 0);
	left = max(left, right / D);

	int mid = left + (right - left) / 2;
	while (left < right) {
		mid = left + (right - left) / 2;
		int good = 0;
		int day = 0;
		int i = 0;
		for (int i = 0; i < weights.size(); ++i) {
			if (good + weights[i] > mid) {
				good = 0;
				day += 1;
			}
			good += weights[i];
		}
		if (good) {
			day += 1;
		}
		
		if (day == D) {
			break;
		} else if (day > D) {
			left = mid+1;
		} else {
			right = mid;
		}

	}
	return mid;
}


int main()
{
	vector<int> data {1,2,3,4,5,6,7,8,9,10};
	cout << shipWithinDays(data, 5) << endl;
	return 0;
}