/*
 * [263] Ugly Number
 *
 * https://leetcode.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (39.48%)
 * Total Accepted:    114.5K
 * Total Submissions: 290K
 * Testcase Example:  '-2147483648'
 *
 *
 * Write a program to check whether a given number is an ugly number.
 *
 *
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 6, 8 are ugly while 14 is not ugly since it includes another
 * prime factor 7.
 *
 *
 *
 * Note that 1 is typically treated as an ugly number.
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
    bool isUgly(int num) {
        if(num<=0) return false;
        if(num==1||num==2||num==3||num==5) return true;
        if(num%2!=0 && num%3!=0 && num%5!=0) return false;
        while(num%2==0){
            num/=2;
        }
        if(num==1)return true;
        while(num%3==0){
            num/=3;
        }
        if(num==1) return true;
        while(num%5==0){
            num/=5;
        }
        if(num==1) return true;
        else return false;

    }
};
