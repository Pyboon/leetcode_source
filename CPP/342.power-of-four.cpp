/*
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (38.78%)
 * Total Accepted:    77.3K
 * Total Submissions: 199K
 * Testcase Example:  '16'
 *
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 *
 * Example:
 * Given num = 16, return true.
 * Given num = 5, return false.
 *
 *
 * Follow up: Could you solve it without loops/recursion?
 *
 * Credits:Special thanks to @yukuairoy  for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(((num)&(num-1))==0 && (num & 0x55555555)){
            return true;
        }
        else return false;
    }
};
