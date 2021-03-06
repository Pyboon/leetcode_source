/*
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (45.16%)
 * Total Accepted:    26.1K
 * Total Submissions: 57.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array, find three numbers whose product is maximum and
 * output the maximum product.
 *
 * Example 1:
 *
 * Input: [1,2,3]
 * Output: 6
 *
 *
 *
 * Example 2:
 *
 * Input: [1,2,3,4]
 * Output: 24
 *
 *
 *
 * Note:
 *
 * The length of the given array will be in range [3,104] and all elements are
 * in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of
 * 32-bit signed integer.
 *
 *
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // int len = nums.size();
        //
        // for(int i = 0;i<len;i++){
        //     cout<<nums[i]<<" ";
        // }
        if(nums[0]*(*(nums.end()-1))>=0){
            return (*(nums.end()-1))*(*(nums.end()-2))*(*(nums.end()-3));
        }
        else{
            if(nums[1]<0){
                return max(nums[0]*nums[1]*(*(nums.end()-1)),(*(nums.end()-1))*(*(nums.end()-2))*(*(nums.end()-3)));
            }
            else {
                return (*(nums.end()-1))*(*(nums.end()-2))*(*(nums.end()-3));
            }
        }

    }
};
