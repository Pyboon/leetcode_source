/*
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (37.85%)
 * Total Accepted:    20.9K
 * Total Submissions: 55.3K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 *
 * Given an array consisting of n integers, find the contiguous subarray of
 * given length k that has the maximum average value. And you need to output
 * the maximum average value.
 *
 *
 * Example 1:
 *
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 *
 *
 *
 * Note:
 *
 * 1 k n
 * Elements of the given array will be in the range [-10,000, 10,000].
 *
 *
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int len = nums.size();
        for(int i = 0;i<k;i++){
            sum += nums[i];
        }
        int maxresult = sum;
        for(int i = k;i<len;i++){
            sum = sum-nums[i-k]+nums[i];
            if(sum>maxresult){
                maxresult = sum;
            }
        }
        return maxresult/double(k);
    }
};
