/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (47.35%)
 * Total Accepted:    231.4K
 * Total Submissions: 488.6K
 * Testcase Example:  '[1]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        std::unordered_map<int ,int> arr;
        for (int i = 0;i<len;i++){
            if(arr.find(nums[i])!=arr.end()){
                arr[nums[i]]++;
            }
            else {
                arr.insert ({{nums[i],1}});
            }
            if(arr[nums[i]]>len/2){
                return nums[i];
            }
        }

    }
};
