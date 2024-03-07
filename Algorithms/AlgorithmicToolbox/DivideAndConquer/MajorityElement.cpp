/*
Majority Element Problem
Check whether a given sequence of numbers con- tains an element that appears more than half of the times.
Input: A sequence of n integers.
Output: 1, if there is an element that is repeated more than n/2 times, and 0 otherwise.
Input format. The first line contains an integer n, the next one contains a sequence of n
non-negative integers. a0,...,an−1.
Outputformat. Output1ifthesequencecontainsanelementthatappears more than n/2 times, and 0 otherwise.

Constraints. 1≤n≤105;0≤ai ≤109 forall0≤i<n.

*/
#include <iostream>
#include <vector>

int findMajorityElement(std::vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;

    for(int i=1; i<nums.size(); ++i) {
        if(nums[i] == candidate) {
            count++;
        }
        else {
            count--;
        }

        if(count == 0) {
            candidate = nums[i];
            count = 1;
        }
    }

    count = 0;
    for(int n : nums) {
        if(n == candidate) {
            count++;
        }
    }

    if(count > (nums.size())/2) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0; i<n; ++i) {
        std::cin >> nums[i];
    }
    std::cout << findMajorityElement(nums) << '\n';

    return 0;
}