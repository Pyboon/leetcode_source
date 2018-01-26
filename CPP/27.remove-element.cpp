/*
 * [27] Remove Element
 *
 * https://leetcode.com/problems/remove-element
 *
 * algorithms
 * Easy (39.79%)
 * Total Accepted:    236.6K
 * Total Submissions: 594.3K
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * Given an array and a value, remove all instances of that value in-place and
 * return the new length.
 * 
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 * 
 * 
 * Example:
 * 
 * Given nums = [3,2,2,3], val = 3,
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 2.
 * 
 * 
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      if(nums.size()==0) return 0;
        vector<int>::iterator it = nums.begin();
        for(;it!=nums.end();){
          if(*it==val){
            nums.erase(it);
          }
          else{
            ++it;
          }
        }
        return nums.size();
    }
};
