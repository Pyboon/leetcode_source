/*
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (40.51%)
 * Total Accepted:    112.3K
 * Total Submissions: 277K
 * Testcase Example:  '27'
 *
 *
 * ⁠   Given an integer, write a function to determine if it is a power of
 * three.
 *
 *
 * ⁠   Follow up:
 * ⁠   Could you do it without using any loop / recursion?
 *
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        int temp = (int)log(INT_MAX)/log(3);
        temp = pow(3,(double)temp);
        return temp % n==0?true:false;
    }
};
