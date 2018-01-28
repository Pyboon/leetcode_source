/*
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (38.52%)
 * Total Accepted:    61.5K
 * Total Submissions: 159.7K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 *
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 *
 * Example 1:
 *
 * Input: 16
 * Returns: True
 *
 *
 *
 * Example 2:
 *
 * Input: 14
 * Returns: False
 *
 *
 *
 * Credits:Special thanks to @elmirap for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<=0) return false;
        double xn = num/2;
        double xn1 = xn+1;
        while(abs(xn-xn1)>1e-12){
            xn = xn1;
            xn1 = xn-(double)(xn*xn-num)/(2*xn);

        }
        if(xn1-int(xn1)<1e-4)return true;
        else return false;
    }
};
