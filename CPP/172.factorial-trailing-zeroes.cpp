/*
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (36.55%)
 * Total Accepted:    106K
 * Total Submissions: 290K
 * Testcase Example:  '0'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int count  = 0;
        while(n>4){
            n /= 5;
            count+=n;
        }
        return count;
    }
};
