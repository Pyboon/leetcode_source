/*
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (30.12%)
 * Total Accepted:    30.4K
 * Total Submissions: 100.8K
 * Testcase Example:  '3'
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ...
 *
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 231).
 *
 *
 * Example 1:
 *
 * Input:
 * 3
 *
 * Output:
 * 3
 *
 *
 *
 * Example 2:
 *
 * Input:
 * 11
 *
 * Output:
 * 0
 *
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 *
 *
 */
class Solution {
public:
    int findNthDigit(int n) {
        if(n<10)return n;
        int count = 1;
        long multi = 1;
        int num = 0;
        int temp = n;
        while(temp>9*multi*count){
            num+=9*multi;
            temp -=9*multi*count;
            count++;
            multi*=10;
        }
        int offset = temp%count;
        int pos = num+temp/count+(offset!=0);
        if(offset){
            offset = count-offset;
            while(offset){
                pos/=10;
                offset--;
            }
        }

        return pos%10;

    }
};
