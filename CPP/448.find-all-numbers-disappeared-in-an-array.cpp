/*
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (51.31%)
 * Total Accepted:    70.6K
 * Total Submissions: 137.7K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 *
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 *
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [5,6]
 *
 *
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int > result;
        bitset<100000> bits;
        int len = nums.size();
        for(int i = 0;i<len;i++){
            bits.set(nums[i]);
        }
        for(int i = 1;i<len+1;i++){
            if(bits[i]==0){
                result.push_back(i);
            }
        }
        return result;
    }
};
