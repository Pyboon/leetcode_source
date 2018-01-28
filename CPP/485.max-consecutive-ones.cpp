/*
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (53.99%)
 * Total Accepted:    65.9K
 * Total Submissions: 122.1K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 *
 * Example 1:
 *
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s.
 * ⁠   The maximum number of consecutive 1s is 3.
 *
 *
 *
 * Note:
 *
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 *
 *
 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        int maxcount = INT_MIN;
        for(int i = 0;i<len;i++){
            if(nums[i]){
                count++;
            }
            else {
                count = 0;
            }
            if(count>maxcount){
                maxcount = count;
            }
        }
        return maxcount;
    }
};
