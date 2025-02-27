#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

/*
Time Complexity O(logn)

*/

#include <vector>
using namespace std;

class BinarySearch {
public:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int lowerBound(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return (nums[left] >= target) ? left : -1;
    }

    int upperBound(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        return (nums[left] > target) ? left : -1;
    }

    int firstLessThan(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid - 1;
            else {
                result = mid;
                left = mid + 1;
            }
        }
        return result;
    }

    int searchRotatedArray(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[left] <= nums[mid]) {
                if (target < nums[mid] && nums[left] <= target) right = mid - 1;
                else left = mid + 1;
            } else {
                if (target > nums[mid] && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }

    int binarySearchRecursive(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return binarySearchRecursiveHelper(nums, target, 0, nums.size() - 1);
    }


private:
    int binarySearchRecursiveHelper(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target)
            return binarySearchRecursiveHelper(nums, target, mid + 1, right);
        return binarySearchRecursiveHelper(nums, target, left, mid - 1);
    }


};

#endif