/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one
 *
 * algorithms
 * Easy (39.06%)
 * Total Accepted:    200.7K
 * Total Submissions: 513.6K
 * Testcase Example:  '[0]'
 *
 * Given a non-negative integer represented as a non-empty array of digits,
 * plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carrybit = 1;
        for(int i = len-1;i>=0;i--){
          digits[i] = carrybit+digits[i];
          if(digits[i]>9){
            carrybit = 1;
            digits[i] = digits[i]%10;
          }
          else {

            carrybit = 0;
          }
        }
        if(carrybit){
          vector<int>::iterator it = digits.begin();
          digits.insert(it,1);
        }
        return digits;
    }
};
