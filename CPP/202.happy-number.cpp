/*
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (41.14%)
 * Total Accepted:    145.3K
 * Total Submissions: 353.1K
 * Testcase Example:  '1'
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 *
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 *
 *
 * Credits:Special thanks to @mithmatt and @ts for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    bool isHappy(int n) {
        int count = 0;
        while(n!=1){
            if(count<10000){
                count++;
                n = dpart(n);
            }
            else return false;

        }
        return true;
    }
    int dpart(int n){
        int sum = 0;
        while(n){
            sum+=(n%10)*(n%10);
            n  = n/10;
        }
        return sum;
    }
};
