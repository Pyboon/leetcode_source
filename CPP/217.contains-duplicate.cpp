/*
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (46.45%)
 * Total Accepted:    187.2K
 * Total Submissions: 403K
 * Testcase Example:  '[]'
 *
 *
 * Given an array of integers, find if the array contains any duplicates. Your
 * function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 *
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len<2)return false;
        std::sort(nums.begin(),nums.end());
        for (int i = 0;i<len-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};
