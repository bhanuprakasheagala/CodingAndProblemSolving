/*
Given an integer array nums of size n, return the number with the value closest to 0 in nums.
If there are multiple answers, return the number with the largest value.

Example 1:
Input: nums = [-4,-2,1,4,8]
Output: 1
Explanation:
The distance from -4 to 0 is |-4| = 4.
The distance from -2 to 0 is |-2| = 2.
The distance from 1 to 0 is |1| = 1.
The distance from 4 to 0 is |4| = 4.
The distance from 8 to 0 is |8| = 8.
Thus, the closest number to 0 in the array is 1.

Example 2:
Input: nums = [2,-1,1]
Output: 1
Explanation: 1 and -1 are both the closest numbers to 0, so 1 being larger is returned.
*/
#include <vector>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::abs;
using std::max;

int findClosestNumber(const vector<int>& nums) {
    int n = nums.size();
    int res = INT_MAX;
    for(int i = 0; i < n; ++i) {
        if(abs(nums[i]) < abs(res)) {
            res = nums[i];
        }
        else if(abs(nums[i]) == abs(res)) {
            res = max(res, nums[i]);
        }
    }
    return res;
}

int main() {
    vector<int> nums1 = {-4, -2, 1, 4, 8};
    vector<int> nums2 = {2, -1, 1};

    cout << findClosestNumber(nums1) << endl; // Expected output: 1
    cout << findClosestNumber(nums2) << endl; // Expected output: 1

    return 0;
}