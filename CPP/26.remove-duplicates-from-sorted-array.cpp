/*
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array
 *
 * algorithms
 * Easy (35.47%)
 * Total Accepted:    283.6K
 * Total Submissions: 799.4K
 * Testcase Example:  '[1,1,2]'
 *
 * 
 * Given a sorted array, remove the duplicates in-place such that each element
 * appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * 
 * Example:
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 * 
 * 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.size()==0) return 0;
      vector<int>::iterator it = nums.begin();
        for (;it!=nums.end()-1;){
          if(*it == *(it+1) ){
            nums.erase(it+1);
          }
          else {
            ++it;
          }
        }
        return nums.size();
    }
};
