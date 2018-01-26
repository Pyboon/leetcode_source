/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position
 *
 * algorithms
 * Easy (39.84%)
 * Total Accepted:    213.5K
 * Total Submissions: 536K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right  = len-1;
        int medium ;
        while(left<=right){
          medium = (left+right)/2;
          if(nums.at(medium)<target){
            left = medium+1;
          }
          else if(nums.at(medium)>target){
            right = medium-1;
          }
          else return medium;

        }
        int index = nums[medium]>target?medium:medium+1;
        return index;
    }
};
