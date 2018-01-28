/*
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (27.94%)
 * Total Accepted:    50.3K
 * Total Submissions: 179.9K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 *
 * Example 1:
 *
 * Input: [3, 2, 1]
 *
 * Output: 1
 *
 * Explanation: The third maximum is 1.
 *
 *
 *
 * Example 2:
 *
 * Input: [1, 2]
 *
 * Output: 2
 *
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 *
 *
 *
 * Example 3:
 *
 * Input: [2, 2, 3, 1]
 *
 * Output: 1
 *
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 *
 *
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first  = nums[0];
        int second = INT_MIN;
        int third = INT_MIN;
        int len = nums.size();
        int count = 1;
        bool flag = false;
        for(int i = 1;i<len;i++){
            if(nums[i]>=first){
                if(nums[i]!=first){
                    count++;
                    third = second;
                    second = first;
                    first = nums[i];
                }

            }
            else if(nums[i]>=second){
                if(nums[i]!=second){
                    count++;
                    third = second;
                    second = nums[i];
                }
                else if(nums[i]==INT_MIN && !flag){
                    count++;
                    flag = true;
                }
            }
            else if(nums[i]>=third){
                count++;
                third = nums[i];
            }
        }
        if(count<3){
            return first;
        }
        else return third;
    }
};
