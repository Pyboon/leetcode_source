/*
 * [479] Largest Palindrome Product
 *
 * https://leetcode.com/problems/largest-palindrome-product/description/
 *
 * algorithms
 * Easy (24.81%)
 * Total Accepted:    8K
 * Total Submissions: 32.2K
 * Testcase Example:  '1'
 *
 * Find the largest palindrome made from the product of two n-digit numbers.
 * ⁠Since the result could be very large, you should return the largest
 * palindrome mod 1337.
 *
 * Example:
 * Input: 2
 * Output: 987
 * Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
 *
 *
 *
 *
 * Note:
 * The range of n is [1,8].
 *
 *
 */

class Solution {
public:
    int largestPalindrome(int n) {
        int top = 1;
        while(n){
            top*=10;
            --n;
        }
        --top;//999...

    }
};
