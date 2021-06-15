//
// Created by Apple on 2021/6/15.
//

#include <vector>

using namespace std;

/**
 * 保证数组是一个山峰的前提下，找到峰顶的下标（山峰是指从峰顶到两边，严格下降）
 *
 * https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
 * 线性时间复杂度，效率较低
 * @param arr
 * @return
 */
int line_peakIndexInMountainArray(vector<int>& arr) {
    int indexOfPeak = 0;
    int maxValue = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            indexOfPeak = i;
        }
    }
    return indexOfPeak;
}

/**
 * 使用二分法查找峰顶，每次都对当前mid元素判断处于山峰左侧或右侧，左侧则右移，右侧则左移
 * @param arr
 * @return
 */
int peakIndexInMountainArray(vector<int>& arr) {
    const size_t SIZE = arr.size();
    int indexOfPeak = 0;
    for (size_t left = 0, right = SIZE - 1; left < right; ) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            indexOfPeak = mid;
            break;
        } else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) {
            right = mid;
        } else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {
            left = mid;
        } else {
            // pass
        }
    }

    return indexOfPeak;
}


int main()
{
    return 0;
}