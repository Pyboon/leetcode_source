/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray
 *
 * algorithms
 * Easy (39.94%)
 * Total Accepted:    252.8K
 * Total Submissions: 633K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest sum.
 * 
 * 
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int pre = 0;
      int max = nums[0];
      int len = nums.size();
      for (int i = 0; i<len;i++){
        pre = pre+nums[i]>nums[i] ? pre+nums[i]:nums[i];
        // cout<<pre<<endl;
        if(pre>=max){
          max = pre;
        }
      }
      return max;
  }
};
