/*
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (40.47%)
 * Total Accepted:    156.9K
 * Total Submissions: 387.7K
 * Testcase Example:  '1'
 *
 *
 * Given an integer, write a function to determine if it is a power of two.
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        return ((n-1)&n) == 0;
    }
};
