#include <iostream>
#include <vector>

// 二分查找函数
int binarySearch(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;  // 找到目标元素，返回索引
        } else if (nums[mid] < target) {
            left = mid + 1;  // 目标元素在右半部分，调整左边界
        } else {
            right = mid - 1;  // 目标元素在左半部分，调整右边界
        }
    }

    return -1;  // 没有找到目标元素，返回 -1
}

int main() {
    std::vector<int> nums = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;

    int index = binarySearch(nums, target);

    if (index != -1) {
        std::cout << "目标元素 " << target << " 的索引为 " << index << std::endl;
    } else {
        std::cout << "目标元素 " << target << " 不存在于数组中" << std::endl;
    }

    return 0;
}
