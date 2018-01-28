/*
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.33%)
 * Total Accepted:    24.6K
 * Total Submissions: 84K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 *
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 *
 *
 *
 * Note:
 *
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means .
 *
 *
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len  = nums.size();
        if(len<2)return 0;
        int i = 0;
        int j = len-1;
        bool left = false;
        bool right = false;
        int leftcount = 0;
        int rightcount = 0;
        while(i<=j){
            if(nums[i]<nums[i+1]){
                leftcount=0;
                i++;
            }
            else if(nums[i]==nums[i+1]){
                leftcount++;
                i++;
            }
            else {
                left = true;
            }
            if(nums[j]>nums[j-1]){
                rightcount=0;
                j--;
            }
            else if(nums[j]==nums[j-1]){
                rightcount++;
                j--;
            }

            else {
                right = true;
            }
            if(left && right)break;
        }
        int minleft = INT_MAX;
        int maxright = INT_MIN;
        for(int k = i;k<=j;k++){
            if(nums[k]<=nums[i] && nums[k]<minleft){
                minleft = nums[k];
            }
            if(nums[k]>=nums[j] && nums[k]>maxright){
                maxright = nums[k];
            }
        }
        int lpos = i;
        int rpos = j;
        for(int k = 0;k<i;k++){
            if(nums[k]>minleft){
                lpos = k;
                break;
            }
        }
        int k;
        for(k = j+1;k<len;k++){
            if(nums[k]>=maxright){
                rpos = k-1;
                break;
            }
        }
        if(k==len){
            rpos=len-1;
        }
        return rpos-lpos>=0?rpos-lpos+1:0;
        // return j-i>=0?j-i+leftcount+rightcount+1:0;
    }
};
