/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (39.52%)
 * Total Accepted:    170.4K
 * Total Submissions: 431.2K
 * Testcase Example:  '[]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Also thanks to @ts for adding additional test cases.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(!len)return 0;
        int result[len];
        for (int i = 0;i<len;i++){
            if(i==0)result[i] = nums[i];
            else if(i==1)result[i] = nums[i]>result[i-1]?nums[i]:result[i-1];
            else result[i] = result[i-1]>result[i-2]+nums[i]?result[i-1]:result[i-2]+nums[i];
        }
        return result[len-1];
    }
};
