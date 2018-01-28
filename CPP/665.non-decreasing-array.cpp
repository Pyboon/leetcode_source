/*
 * [665] Non-decreasing Array
 *
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Easy (20.84%)
 * Total Accepted:    15.3K
 * Total Submissions: 73.5K
 * Testcase Example:  '[4,2,3]'
 *
 *
 * Given an array with n integers, your task is to check if it could become
 * non-decreasing by modifying at most 1 element.
 *
 *
 *
 * We define an array is non-decreasing if array[i]  holds for every i (1
 *
 * Example 1:
 *
 * Input: [4,2,3]
 * Output: True
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing
 * array.
 *
 *
 *
 * Example 2:
 *
 * Input: [4,2,1]
 * Output: False
 * Explanation: You can't get a non-decreasing array by modify at most one
 * element.
 *
 *
 *
 * Note:
 * The n belongs to [1, 10,000].
 *
 */
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        if(len==1)return true;
        int curmax = INT_MIN;

        int i =0;
        int j = len-1;
        int lmax = INT_MIN;
        int rmin = INT_MAX;
        bool lstop = false;
        bool rstop = false;
        while(i<=j){
            if(nums[i+1]>=nums[i]){

                i++;
            }
            else lstop = true;
            lmax = lmax>nums[i]?lmax:nums[i];
            if(nums[j-1]<=nums[j]){

                j--;
            }
            else rstop = true;
            rmin = rmin<nums[j]?rmin:nums[j];
            if(lstop && rstop)break;
        }
        if(j-i<=0)return true;
        if(j-i>1)return false;
        int lcount = 0;
        int rcount = 0;
        for(int k = 0;k<=i;k++){
            if(nums[k]>rmin)lcount++;
        }
        for(int k = j;k<len;k++){
            if(nums[k]<lmax)rcount++;
        }
        if(lcount<=1 || rcount<=1)return true;
        else return false;

    }
};
