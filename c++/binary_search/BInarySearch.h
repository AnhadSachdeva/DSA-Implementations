#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

using namespace std;

#include <vector>

class BinarySearch {

    public:
        // Finds the index of target in a sorted array nums. Returns -1 if not found.
        int binarySearch(vector<int>& nums, int target){
            int left = 0;
            int right = nums.size()-1;

            while(left <= right){
                int mid = left + (right - left) /2;

                if(nums[mid] == target) return mid;
                else if(nums[mid] < target){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            return -1;
        }
        // Returns the smallest index where nums[index] >= target. Useful for finding the first occurrence or insertion point.
        int lowerBound(vector<int>& nums, int target){
            int left = 0;
            int right = nums.size()-1;

            while(left < right){
                int mid = left + (right - left) /2;

                if(nums[mid] >= target){
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return (nums[left] >= target) ? left : -1;
        }
        // Returns the smallest index where nums[index] > target. Useful for finding the position after the last occurrence.
        int upperBound(vector<int>& nums, int target){
                    int left = 0;
            int right = nums.size()-1;

            while(left < right){
                int mid = left + (right - left) /2;

                if(nums[mid] > target){
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return (nums[left] > target) ? left : -1;
        }
        // Returns the largest index where nums[index] < target. Useful for finding the largest value smaller than the target.
        int firstLessThan(vector<int>& nums, int target){
            int left = 0;
            int right = nums.size()-1;
            int result = -1;
            while(left <= right){
                int mid = left + (right - left) /2;

                if(nums[mid] >= target){
                    right = mid - 1;
                } else {
                    result = mid;
                    left = mid + 1;
                    

                }
            }
            return result;
        }
        // Finds the index of target in a rotated sorted array (e.g., [4, 5, 6, 1, 2, 3]).
        int searchRotatedArray(vector<int>& nums, int target){
            int left = 0;
            int right = nums.size()-1;

            while(left <= right){
                int mid = left + (right - left)/2;

                if(nums[mid] == target){
                    return mid;
                }

                // left side is sorted
                if(nums[left] <= nums[mid]){
                    // answer is in [left,mid)
                    if(target < nums[mid] && nums[left] <= target){
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else {
                     // answer is in (mid,right]
                    if(target > nums[mid] && nums[right] >= target){
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

            }

            return -1;

        }

        int findMinSubarray(vector<int>& nums, int target){

        }
       

       int binarySearchRecursive(vector<int>& nums, int target){

       }
        





};


#endif