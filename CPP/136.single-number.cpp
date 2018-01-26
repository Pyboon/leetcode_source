/*
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number
 *
 * algorithms
 * Easy (54.94%)
 * Total Accepted:    257.7K
 * Total Submissions: 468.5K
 * Testcase Example:  '[1]'
 *
 * Given an array of integers, every element appears twice except for one. Find
 * that single one.
 * 
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int , int > array;
        int len = nums.size();
        for (int i =0;i<len;i++){
          if(array.find(nums[i])!=array.end()){
            array[nums[i]] +=1;
          }
          else {
            array.insert ({{nums[i],1}});
          }
        }

        for (int i =0;i<len;i++){
          if(array[nums[i]]==1){
            return nums[i];
          }
        }

    }
};
