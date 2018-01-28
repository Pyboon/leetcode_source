/*
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (50.89%)
 * Total Accepted:    241.5K
 * Total Submissions: 474.4K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 *
 *
 *
 * For example, given nums  = [0, 1, 0, 3, 12], after calling your function,
 * nums should be [1, 3, 12, 0, 0].
 *
 *
 *
 * Note:
 *
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 *
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int len  = nums.size();
        for (int i  = len-1;i>=0;i--){
            if(nums[i]==0){
                for(int j = i+1;j<len-count;j++){
                    nums[j-1] = nums[j];
                }
                count++;
                nums[len-count] = 0;
            }
        }
        // for(int i = len-1;i>len-1-count;i--){
        //     nums[i] = 0;
        // }
    }
};
